/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：usart.c
 * 描述    ：将printf函数重定向到USART1。这样就可以用printf函数将单片机的数据打
 *           印到PC上的超级终端或串口调试助手。     
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2017-05-11
 * 硬件连接: TX->PA9;RX->PA10
 * 调试方式：J-Link-OB
**********************************************************************************/	

//头文件
#include "usart.h"
#include "driver.h"
#include "ptz.h"
#include <string.h>

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#define MAX_SIZE 256
  
uint8_t USART_RxBuff[MAX_SIZE] = "";
uint8_t USART_RxCount = 0;
uint8_t start_flag = 0;
  
extern char ptz_flag;
 /**
  * @file   USART1_Config
  * @brief  USART1 GPIO 配置,工作模式配置。9600-8-N-1
  * @param  无
  * @retval 无
  */
void USART1_Config(void)
{	
    GPIO_InitTypeDef GPIO_InitStructure;	
    USART_InitTypeDef USART_InitStructure;  //定义串口初始化结构体
    RCC_APB2PeriphClockCmd( USART_RCC | USART_GPIO_RCC,ENABLE);

    /*USART1_TX ->PA9*/			
    GPIO_InitStructure.GPIO_Pin = USART_TX;	       //选中串口默认输出管脚         
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //定义输出最大速率 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//定义管脚9的模式  
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);           //调用函数，把结构体参数输入进行初始化		   
    /*USART1_RX ->PA10*/
    GPIO_InitStructure.GPIO_Pin = USART_RX;	        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);
    /*串口通讯参数设置*/
    USART_InitStructure.USART_BaudRate = BaudRate; //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
    USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
    USART_InitStructure.USART_Parity = USART_Parity_No;		//校验位 无
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//使能接收和发送引脚

    USART_Init(USART, &USART_InitStructure);
	USART_ClearFlag(USART,USART_FLAG_TC);
	USART_ITConfig(USART, USART_IT_RXNE, ENABLE);		
    USART_Cmd(USART, ENABLE);
}

uint8_t checksum(uint8_t *addr, int count)	//count字节数, 计算8位校验和
{
	short sum = 0;

    while (count > 1)
	{
        sum += *(uint8_t *)addr++;
        count -= 1;
    }   

    if (count > 0)
	{ 
        char left_over[2] = {0};
        left_over[0] = *addr;
        sum += * (uint8_t *)left_over;
    }   
    while (sum >> 8)
	{
		sum = (sum & 0xff) + (sum >> 8);
	}
	
	return ~sum;
}


void command(uint8_t *cmd)
{
	if (0x00 != checksum(cmd, USART_RxCount))
	{
		return ;
	}		
	switch (cmd[1])	//移动方向
	{
		case '0' :
			stop();
			break;
		case '1' :
			forward();
			break;
		case '2' :
			right();
			break;
		case '3' :
			backward();
			break;
		case '4' :
			left();
			break;
		default :
			break;
	}
			
	switch (cmd[2])	//移动速度
	{
		case '1' :
			set_speed(1);
			break;
		case '2' :
			set_speed(2);
			break;
		case '3' :
			set_speed(3);
			break;
		default :
			break;
	}
    ptz_flag = cmd[3];		//舵机
}
 /**
  * @file   USART1_IRQHandler
  * @brief  中断处理函数
  * @param  无
  * @retval 无
  */
void USART1_IRQHandler(void)
{
	uint8_t res;
	int i = 0;

	if(USART_GetITStatus(USART, USART_IT_RXNE) != RESET)
	{ 	
		res = USART_ReceiveData(USART); 
		if ('K' == res)		//接收开始
		{
			start_flag = 1;
		}
		
		if (start_flag)
		{
			USART_RxBuff[USART_RxCount] = res;
			USART_RxCount++;
			
			if (USART_RxBuff[USART_RxCount-1] == 'S')   //接收结束
			{
				command(USART_RxBuff);

				USART_RxCount = 0;
				memset(USART_RxBuff, 0, sizeof(USART_RxBuff));
				start_flag = 0;
			}
		}
		
		USART_ClearFlag(USART, USART_FLAG_TC);
	} 
}
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int fputc(int ch, FILE *f)
{
  USART_SendData(USART, (uint8_t) ch);

  while (USART_GetFlagStatus(USART, USART_FLAG_TC) == RESET)
  {}
  return (ch);
}
