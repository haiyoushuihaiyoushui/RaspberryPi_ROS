/******************** (C) COPYRIGHT  Դ�ع����� ********************************
 * �ļ���  ��led.c
 * ����    ��LED����������     
 * ����    ��zhuoyingxingyu
 * �Ա�    ��Դ�ع�����http://vcc-gnd.taobao.com/
 * ��̳��ַ������԰��-Ƕ��ʽ������̳http://vcc-gnd.com/
 * �汾����: 2015-10-20
 * Ӳ������: D1->PC13;D2->PB0;D4->PB1
 * ���Է�ʽ��J-Link-OB
**********************************************************************************/	

//ͷ�ļ�
#include "led.h"

 /**
  * @file   LED_GPIO_Config
  * @brief  LED����������
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{	
    //����һ��GPIO_InitTypeDef ���͵Ľṹ��
    GPIO_InitTypeDef  GPIO_InitStructure;	
    RCC_APB2PeriphClockCmd(LED1_GPIO_RCC,ENABLE);//ʹ��GPIO������ʱ��
    /*D1*/
    GPIO_InitStructure.GPIO_Pin =LED1_GPIO_PIN;//ѡ��Ҫ�õ�GPIO����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //��������ģʽΪ�������ģʽ						 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//���������ٶ�Ϊ50MHZ         
    GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);//���ÿ⺯������ʼ��GPIO
}

