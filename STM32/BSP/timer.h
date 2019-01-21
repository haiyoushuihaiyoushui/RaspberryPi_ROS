#ifndef TIME_TEST_H
#define TIME_TEST_H

#include "stm32f10x.h"
#include "stm32f10x_tim.h" 


#define PWM_GPIO_RCC			RCC_APB2Periph_GPIOB
#define PWM1_GPIO_PORT          GPIOB
#define PWM1_GPIO_PIN      		GPIO_Pin_6	

#define PWM2_GPIO_PORT          GPIOB
#define PWM2_GPIO_PIN      		GPIO_Pin_7	

#define PWM3_GPIO_PORT          GPIOB
#define PWM3_GPIO_PIN      		GPIO_Pin_8	

#define PWM4_GPIO_PORT          GPIOB
#define PWM4_GPIO_PIN      		GPIO_Pin_9	

void NVIC_init(void);
void Tim1_Init(void);
void Tim2_Init(void);
void Tim3_Init(void);
void Tim4_Init(void);
void GPIO_TimPWM(void);

#endif	/* TIME_TEST_H */
