#include "driver.h"

extern float v;
void L298N_init(void)
{	
    //定义一个GPIO_InitTypeDef 类型的结构体
    GPIO_InitTypeDef  GPIO_InitStructure;	
    RCC_APB2PeriphClockCmd(L298N1_GPIO_RCC, ENABLE);//使能GPIO的外设时钟

    GPIO_InitStructure.GPIO_Pin = L298N1_GPIO_IN1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 						 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;         
    GPIO_Init(L298N1_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = L298N1_GPIO_IN2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;         
    GPIO_Init(L298N1_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = L298N1_GPIO_IN3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 					 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       
    GPIO_Init(L298N1_GPIO_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = L298N1_GPIO_IN4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 						 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;        
    GPIO_Init(L298N1_GPIO_PORT, &GPIO_InitStructure);
}

void stop(void)
{
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN1, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN2, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN3, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN4, Bit_RESET);
	v = 0;
}

void forward(void)
{
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN1, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN2, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN3, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN4, Bit_RESET);
}

void left(void)
{
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN1, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN2, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN3, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN4, Bit_SET);
}

void backward(void)
{
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN1, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN2, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN3, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN4, Bit_SET);
}

void right(void)
{
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN1, Bit_RESET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN2, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN3, Bit_SET);
	GPIO_WriteBit(L298N1_GPIO_PORT, L298N1_GPIO_IN4, Bit_RESET);
}

void set_speed(uint8_t speed)
{
	switch (speed)
	{
		case 1 :
			TIM_SetCompare3(TIM4, 7000);
			TIM_SetCompare4(TIM4, 5000);
			break;
		case 2 :
			TIM_SetCompare3(TIM4, 6000);
			TIM_SetCompare4(TIM4, 3000);
			break;
		case 3 :
			TIM_SetCompare3(TIM4, 4000);
			TIM_SetCompare4(TIM4, 1000);
			break;
		default :
			break;
	}
}
