#include "ptz.h"
#include "timer.h"
#include "usart.h"

#define MAX_ANGLE	170
#define MIN_ANGLE	10

int global_angle_lr = 0;
int global_angle_ud = 0;
char ptz_flag = '0';

void set_angle_lr(int angle)
{
	global_angle_lr = angle;
	angle = (u16)(4.175*angle + 409.25); 	
	TIM_SetCompare1(TIM4, angle);
}

void set_angle_ud(int angle)
{
	global_angle_ud = angle;
	angle = (u16)(4.175*angle + 409.25); 	
	TIM_SetCompare2(TIM4, angle);
}

void turn_left(void)
{
	if (global_angle_lr + 1 <= MAX_ANGLE)
	{
		set_angle_lr(global_angle_lr + 1); 
	}
}

void turn_right(void)
{	
	if (global_angle_lr - 1 >= MIN_ANGLE)
	{
		set_angle_lr(global_angle_lr - 1); 
	}

}

void turn_up(void)
{
	if (global_angle_ud - 1 >= MIN_ANGLE)
	{
		set_angle_ud(global_angle_ud - 1); 
	}
}

void turn_down(void)
{
	if (global_angle_ud + 1 <= MAX_ANGLE)
	{
		set_angle_ud(global_angle_ud + 1); 
	}
}

void ptz_contrl(void)
{
	switch (ptz_flag)	//¶æ»ú
	{
		case '0' :
			break;
		case '1' :
			turn_up();
			break;
		case '2' :
	        turn_right();
			break;
		case '3' :
			turn_down();
			break;
		case '4' :
            turn_left();
			break;
		default :
			break;
	}
}
