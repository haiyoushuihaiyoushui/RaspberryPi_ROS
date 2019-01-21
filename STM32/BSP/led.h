#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1_GPIO_RCC           RCC_APB2Periph_GPIOC
#define LED1_GPIO_PORT          GPIOC
#define LED1_GPIO_PIN      		GPIO_Pin_13
#define LED1_ONOFF(x)     		GPIO_WriteBit(LED1_GPIO_PORT, LED1_GPIO_PIN, x);

void LED_GPIO_Config(void);	

#endif
