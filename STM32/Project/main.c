/******************** (C) COPYRIGHT  Դ�ع����� ********************************
 * �ļ���  ��main.c
 * ����    ��ͨ������1��ӡ����Լ�������ַ�������������ϢΪ��9600��N,8��1��  
 * ��汾  ��V3.50
 * ����    ��zhuoyingxingyu
 * �Ա�    ��Դ�ع�����http://vcc-gnd.taobao.com/
 * ��̳��ַ������԰��-Ƕ��ʽ������̳http://vcc-gnd.com/
 * �汾����: 2015-10-20
 * ���Է�ʽ��J-Link-OB
**********************************************************************************/	

//ͷ�ļ�
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
	SystemInit();//����ϵͳʱ��Ϊ72M
	/*��ʼ��LED�˿�*/
	LED_GPIO_Config();
	//�ж����ȼ�����
	NVIC_init();
    USART1_Config();//���ڲ������ó�ʼ��

	Tim2_Init(); //���ڳ��������ݼ��� 	
	Ultrasonic_Config();//�������˿ڳ�ʼ��
	
	L298N_init();
	
	Tim3_Init();		//�������������
	Tim1_Init();		//����תһȦ��ʱ��
	
	GPIO_TimPWM();
	Tim4_Init();		//������·PWM
	
	//���
	TIM_SetCompare3(TIM4, 4000);
	TIM_SetCompare4(TIM4, 4000);
	
	//���
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





