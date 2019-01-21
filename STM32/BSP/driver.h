#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "stm32f10x.h"

#define L298N1_GPIO_RCC		RCC_APB2Periph_GPIOA
#define L298N1_GPIO_IN1		GPIO_Pin_2
#define L298N1_GPIO_IN2		GPIO_Pin_3
#define L298N1_GPIO_IN3		GPIO_Pin_4
#define L298N1_GPIO_IN4		GPIO_Pin_5
#define L298N1_GPIO_PORT	GPIOA   

void L298N_init(void);
void stop(void);
void forward(void);
void right(void);
void backward(void);
void left(void);
void set_speed(uint8_t speed);

#endif
