/******************** (C) COPYRIGHT  Դ�ع����� ********************************
 * �ļ���  ��usart.c
 * ����    ����printf�����ض���USART1�������Ϳ�����printf��������Ƭ�������ݴ�
 *           ӡ��PC�ϵĳ����ն˻򴮿ڵ������֡�     
 * ����    ��zhuoyingxingyu
 * �Ա�    ��Դ�ع�����http://vcc-gnd.taobao.com/
 * ��̳��ַ������԰��-Ƕ��ʽ������̳http://vcc-gnd.com/
 * �汾����: 2017-05-11
 * Ӳ������: TX->PA9;RX->PA10
 * ���Է�ʽ��J-Link-OB
**********************************************************************************/	

//ͷ�ļ�
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
  * @brief  USART1 GPIO ����,����ģʽ���á�9600-8-N-1
  * @param  ��
  * @retval ��
  */
void USART1_Config(void)
{	
    GPIO_InitTypeDef GPIO_InitStructure;	
    USART_InitTypeDef USART_InitStructure;  //���崮�ڳ�ʼ���ṹ��
    RCC_APB2PeriphClockCmd( USART_RCC | USART_GPIO_RCC,ENABLE);

    /*USART1_TX ->PA9*/			
    GPIO_InitStructure.GPIO_Pin = USART_TX;	       //ѡ�д���Ĭ������ܽ�         
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�������������� 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����ܽ�9��ģʽ  
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);           //���ú������ѽṹ�����������г�ʼ��		   
    /*USART1_RX ->PA10*/
    GPIO_InitStructure.GPIO_Pin = USART_RX;	        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);
    /*����ͨѶ��������*/
    USART_InitStructure.USART_BaudRate = BaudRate; //������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;	//ֹͣλ1λ
    USART_InitStructure.USART_Parity = USART_Parity_No;		//У��λ ��
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//ʹ�ܽ��պͷ�������

    USART_Init(USART, &USART_InitStructure);
	USART_ClearFlag(USART,USART_FLAG_TC);
	USART_ITConfig(USART, USART_IT_RXNE, ENABLE);		
    USART_Cmd(USART, ENABLE);
}

uint8_t checksum(uint8_t *addr, int count)	//count�ֽ���, ����8λУ���
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
	switch (cmd[1])	//�ƶ�����
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
			
	switch (cmd[2])	//�ƶ��ٶ�
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
    ptz_flag = cmd[3];		//���
}
 /**
  * @file   USART1_IRQHandler
  * @brief  �жϴ�����
  * @param  ��
  * @retval ��
  */
void USART1_IRQHandler(void)
{
	uint8_t res;
	int i = 0;

	if(USART_GetITStatus(USART, USART_IT_RXNE) != RESET)
	{ 	
		res = USART_ReceiveData(USART); 
		if ('K' == res)		//���տ�ʼ
		{
			start_flag = 1;
		}
		
		if (start_flag)
		{
			USART_RxBuff[USART_RxCount] = res;
			USART_RxCount++;
			
			if (USART_RxBuff[USART_RxCount-1] == 'S')   //���ս���
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
