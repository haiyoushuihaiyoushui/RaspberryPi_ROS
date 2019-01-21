#ifndef PTZ_H
#define PTZ_H

#include "stm32f10x.h"
#include "stm32f10x_tim.h" 

void turn_left(void);
void turn_right(void);
void turn_up(void);
void turn_down(void);
void ptz_contrl(void);
void set_angle_lr(int angle);
void set_angle_ud(int angle);

#endif
