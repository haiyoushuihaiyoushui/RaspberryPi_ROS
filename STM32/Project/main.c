/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：main.c
 * 描述    ：通过串口1打印输出自己输入的字符串；（串口信息为：9600，N,8，1）  
 * 库版本  ：V3.50
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2015-10-20
 * 调试方式：J-Link-OB
**********************************************************************************/	

//头文件
#include "stm32f10x.h"
#include "usart.h"
#include "timer.h"
#include "ultrasonic.h"
#include "led.h"
#include "driver.h"
#include "ptz.h"
#include <string.h>

extern float Distance;
extern float v;

void Delayus(u16 i)
{
	unsigned char t = 0;
	for(;i>0;i--)
	{
		for(t=0;t<2;t++)
		{}
	}
}

void Delayms(u16 t)
{
	while(t--)
	{
		Delayus(1000);
	}
}

void send_data(uint8_t *data, int count)
{
	data[count-2] = checksum(data, count);
	printf("%s", data);
}
/**
  * @file   main
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	int count = 0;
	int data_len = 0;
	char data[24] = {0};
	SystemInit();//配置系统时钟为72M
	/*初始化LED端口*/
	LED_GPIO_Config();
	//中断优先级设置
	NVIC_init();
    USART1_Config();//串口参数配置初始化

	Tim2_Init(); //用于超声波数据计算 	
	Ultrasonic_Config();//超声波端口初始化
	
	L298N_init();
	
	Tim3_Init();		//捕获编码器脉冲
	Tim1_Init();		//计算转一圈的时间
	
	GPIO_TimPWM();
	Tim4_Init();		//产生四路PWM
	
	//电机
	TIM_SetCompare3(TIM4, 4000);
	TIM_SetCompare4(TIM4, 4000);
	
	//舵机
	set_angle_lr(90);
	set_angle_ud(90);
	
	stop();
	//forward();

	LED1_ONOFF(Bit_RESET);

    while (1)
    {
		ptz_contrl();
		Ultrasonic_Measure();
		if (40 == count)
		{
			if(Distance < 450 && v < 100)
			{
				memset(data, 0, sizeof(data));
				sprintf(data, "K%0.2f %0.2f S", Distance, v);
				data_len = strlen(data);
				data[data_len-2] = 0x00;
				send_data((uint8_t *)data, data_len);
			}
			count = 0;
		}
        Delayms(25);
		count++;
    }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/





