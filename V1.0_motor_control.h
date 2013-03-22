#include <timers.h>
#include "sumovore.h"
#include "V1.0_motor_control.h"

void spin_left(void);
void turn_left(void);
void straight_fwd(void);
void straight_bck(void);
void turn_right(void);
void spin_right(void);
void bck_right (void); //90 degree back up turn
void bck_left  (void); //90 degree back up turn
void turn_around (void);//120 degree back up turn turn

signed char challenge=0;


void motor_control(void)
{
     // very simple motor control

     
     if ( SeeLine.b.Center ) straight_fwd();
     else if (SeeLine.b.Left) spin_left();
     else if (SeeLine.b.CntLeft) turn_left();
     else if (SeeLine.b.CntRight) turn_right();
     else if (SeeLine.b.Right) spin_right();
   else if (SeeLine.b.CntLeft & SeeLine.b.Center & SeeLine.b.CntRight) straight_fwd();
    
	 if ( (SeeLine.B ) == 0b00000u) 
	 {
	  challenge=3;
	 }

	 if ( (SeeLine.B) == 0b00111u) 
     {
	 challenge=1;
     }
	
	 if( (SeeLine.B) == 0b11100u)
	 {
	 challenge=2;
     }     
		 		 
	switch (challenge)
	{

	case 0:  //nothing out of order*******************
	{
	break;
	}
	
	case 1: //90 degree right feedback ***************
	{
	OpenTimer0(TIMER_INT_OFF & T0_SOURCE_INT & T0_16BIT & T0_PS_1_32);
	WriteTimer0(0);
	while(ReadTimer0() < 5880)
	{
	straight_fwd();
	}
	
	if((SeeLine.B ) == 0b00000u)
	{
	 while ((SeeLine.B ) == 0b00000u)
	{bck_right;
	}
	}
	CloseTimer0();
	break;
	}
	
	case 2: //90 degree left feedback ***************
	{
	OpenTimer0(TIMER_INT_OFF & T0_SOURCE_INT & T0_16BIT & T0_PS_1_32);
	WriteTimer0(0);
	while(ReadTimer0() < 5880)
	{
	straight_fwd();
	}
	
	if((SeeLine.B ) == 0b00000u)
	{
	 while ((SeeLine.B ) == 0b00000u)
	{bck_left;
	}
	}
	CloseTimer0();
	break;
    
	}
	

	case 3: // no feed back.. dead end or cut in track*******************//not finished
	{
	OpenTimer0(TIMER_INT_OFF & T0_SOURCE_INT & T0_16BIT & T0_PS_1_32);
	WriteTimer0(0);	
	while(ReadTimer0() < 5880)
	{
	straight_fwd();
	}
	
	CloseTimer0();
	break;
	}
}
}
//****************************************************************
//movement based functions
//
void spin_left(void)
{
  set_motor_speed(left, rev_fast, 0); 
  set_motor_speed(right, fast, 0); 
}

void turn_left(void)
{
  set_motor_speed(left, stop, 0); 
  set_motor_speed(right, fast, 0); 
}
void straight_fwd(void)
{
  set_motor_speed(left, slow, 0); 
  set_motor_speed(right, slow, 120); 
}
void spin_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, rev_fast, 0); 
}
void turn_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, stop, 0); 
}

void straight_bck(void)
{
  set_motor_speed(left, rev_fast, 0); 
  set_motor_speed(right, rev_fast, 0);
}

void bck_right (void) //leaves you locking right
{
  set_motor_speed(left, rev_slow, 0); 
  set_motor_speed(right, rev_fast, 0); 	
}

void bck_left (void)  //leaves you looking left
{

set_motor_speed(left, rev_fast, 0); 
set_motor_speed(right, rev_slow, 0); 	

}

void turn_around (void)//not finished
{

}
//************************************************
//
