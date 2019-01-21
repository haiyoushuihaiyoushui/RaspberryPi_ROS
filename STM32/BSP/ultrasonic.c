/*************************************
 * �ļ���  ��main.c
 * ����    �����������
 * ʵ��ƽ̨��STM32F103C8T6
 * ��ע    ��2017.01.08
 * �ӿ�    ��

**********************************************************************************/
#include "ultrasonic.h"
#include "usart.h"
#include "timer.h"
#include "stm32f10x_gpio.h"
#include "driver.h"

#define	TRIG_PORT      GPIOA		//TRIG       
#define	ECHO_PORT      GPIOA		//ECHO 
#define	TRIG_PIN       GPIO_Pin_1   //TRIG     
#define	ECHO_PIN       GPIO_Pin_0	//ECHO 

float Distance;      //������ľ���

/*
 * ��������UltrasonicWave_Configuration
 * ����  ��������ģ��ĳ�ʼ��
 * ����  ����
 * ���  ����	
 */
void Ultrasonic_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;	
  	       
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
  GPIO_InitStructure.GPIO_Pin = TRIG_PIN;					 //PC8��TRIG
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		     //��Ϊ�������ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(TRIG_PORT, &GPIO_InitStructure);	                 //��ʼ������GPIO 

  GPIO_InitStructure.GPIO_Pin = ECHO_PIN;				     //PC9��ECH0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		 //��Ϊ����
  GPIO_Init(ECHO_PORT,&GPIO_InitStructure);						 //��ʼ��GPIO
}

/*
 * ��������DelayTime_us
 * ����  ��1us��ʱ����
 * ����  ��Time   	��ʱ��ʱ�� US
 * ���  ����	
 */
void DelayTime_us(int Time)    
{
   unsigned char i;
   for ( ; Time>0; Time--)
     for ( i = 0; i < 72; i++ );
}

/*
 * ��������UltrasonicWave_CalculateTime
 * ����  ���������
 * ����  ����
 * ���  ����	
 */
void Ultrasonic_Calculate(void)
{
	Distance = TIM_GetCounter(TIM2) * 5 * 34 / 2000.0;
}

/*
 * ��������UltrasonicWave_StartMeasure
 * ����  ����ʼ��࣬����һ��>10us�����壬Ȼ��������صĸߵ�ƽʱ��
 * ����  ����
 * ���  ����	
 */
void Ultrasonic_Measure(void)
{
	GPIO_SetBits(TRIG_PORT,TRIG_PIN); 		  //��>10US�ĸߵ�ƽ
	DelayTime_us(20);		                      //��ʱ20US
	GPIO_ResetBits(TRIG_PORT,TRIG_PIN);
  
	while(!GPIO_ReadInputDataBit(ECHO_PORT,ECHO_PIN));	             //�ȴ��ߵ�ƽ
	TIM_Cmd(TIM2, ENABLE);                                             //����ʱ��
	while(GPIO_ReadInputDataBit(ECHO_PORT,ECHO_PIN));	                 //�ȴ��͵�ƽ
	TIM_Cmd(TIM2, DISABLE);			                                 //��ʱ��2ʧ��
	Ultrasonic_Calculate();									 //�������
	TIM_SetCounter(TIM2,0);
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/

