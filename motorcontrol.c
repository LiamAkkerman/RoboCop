#include "sumovore.h" 
#include "motor_control.h" 
#include <timers.h> 
#include <delays.h> 
 
void spin_left(void); 
void turn_left(void); 
void straight_fwd(void); 
void turn_right(void); 
void spin_right(void); 
void turn180 (void);
void onetwenty_degree_left_turn (void); 
void thirty_degree_left_turn(void);
void thirty_degree_right_turn(void);
void onetwenty_degree_right_turn (void);
void big_gap(void);
void turn_slightright(void);
void turn_harshleft(void);
void turn_harshright(void); 
void turn_slightleft(void);
void motor_control(void) 
{ 
OpenTimer0(TIMER_INT_OFF & T0_16BIT & T0_SOURCE_INT & T0_PS_1_32); 
      
  if ( (SeeLine.B) == 0b00100u) straight_fwd();
    else if ( SeeLine.b.CntLeft ) onetwenty_degree_left_turn();
	else if ( SeeLine.b.Left ) thirty_degree_left_turn();
	else if ( SeeLine.b.Right ) thirty_degree_right_turn();
	else if (SeeLine.b.CntRight) onetwenty_degree_right_turn();
	else if ((SeeLine.B ) == 0b00000u) big_gap();
	else if  ((SeeLine.B ) == 0b11111u) motors_brake_all();

} 
   
void onetwenty_degree_left_turn (void) //This is function for 120 degree 
{
WriteTimer0(0); //clear the timer 
INTCONbits.TMR0IF = 0; //clear the flah 
 
while(ReadTimer0() <= 12763) //This will move the robot fotward 1.70003cm 
{ 
straight_fwd(); 
} 
 
while(ReadTimer0() >= 12763) //This will move past the tape 
{ 
if (SeeLine.b.Left & ReadTimer0() < 15000) //The max distance 
if (SeeLine.b.Center|| SeeLine.b.Right || SeeLine.b.CntRight) //This will have it if any of these sensors are tripped it will move //forward 
{ 
straight_fwd(); 
 
} 
if ((SeeLine.B ) == 0b00000u) //If the track does not continue  //Then the robot will know to turn left 
{ 
turn_slightleft(); 

} 
 
} 
} 
 
 
void thirty_degree_left_turn (void) //function for 30 degree trun 
{
WriteTimer0(0); //starts the timer at 0 
INTCONbits.TMR0IF = 0; //clears the flag 
 
while(ReadTimer0() <= 12763) //move the robot straight forward 
{ 
straight_fwd(); 
} 
 
while(ReadTimer0() >= 12763) //once past the tape 
{ 
if (SeeLine.b.CntLeft & ReadTimer0() < 14000) 
if (SeeLine.b.Center || SeeLine.b.Right || SeeLine.b.CntRight) 
//This will have so that if any of these are tripped 
{ 
straight_fwd(); 
} 
if ((SeeLine.B ) == 0b00000u) //if the robot sees the board it //will know that this is what is happening 
{ 
turn_harshleft(); 
} 
 
} 
} 
 

void thirty_degree_right_turn (void) //function for 30 degree trun 
{
WriteTimer0(0); //starts the timer at 0 
INTCONbits.TMR0IF = 0; //clears the flag 
 
while(ReadTimer0() <= 12763) //move the robot straight forward 
{ 
straight_fwd(); 
} 
 
while(ReadTimer0() >= 12763) //once past the tape 
{ 
if (SeeLine.b.CntRight & ReadTimer0() < 14000) 
if (SeeLine.b.Center || SeeLine.b.Left || SeeLine.b.CntLeft) 
//This will have so that if any of these are tripped 
{ 
straight_fwd(); 
} 
if ((SeeLine.B ) == 0b00000u) //if the robot sees the board it //will know that this is what is happening 
{ 
turn_harshright(); 
} 
 
} 
} 

 
void onetwenty_degree_right_turn (void) //This is function for 120 degree 
{

WriteTimer0(0); //clear the timer 
INTCONbits.TMR0IF = 0; //clear the flah 

 
while(ReadTimer0() <= 12763) //This will move the robot fotward 
{ 
straight_fwd(); 
} 
 
while(ReadTimer0() > 12763) //This will move past the tape 
{ 
if (SeeLine.b.Right & ReadTimer0() < 14000) //The max distance 
if (SeeLine.b.Center|| SeeLine.b.Left || SeeLine.b.CntLeft) 
//This will have it if any of these sensors are tripped it will move //forward 
{ 
straight_fwd(); 
 
} 
if ((SeeLine.B ) == 0b00000u) //If the track does not continue  
//Then the robot will know to turn right 
{ 
turn_slightright(); 

} 
 
} 
} 
 
void big_gap(void) 
{ 
if (((SeeLine.B ) == 0b00000u)) 
{ 
WriteTimer0(0); 
INTCONbits.TMR0IF = 0; //clear the flag 
} 
while (ReadTimer0() < 60060) 
{ 
straight_fwd(); 
} 
while ( ReadTimer0() >= 60060) 
if ((SeeLine.B ) == 0b00000u) 
{ 
turn180(); 

} 
 
if ((SeeLine.B ) == 0b00111u) 
{ 
turn_left(); 

} 
if ((SeeLine.B ) == 0b11100u) 
{ 
turn_right(); 

} 
} 
 
void turn_slightright(void) 
{ 
set_motor_speed(left, slow, 0); 
set_motor_speed(right, medium, 0); 
} 
 
void turn_harshleft(void)
{ 
set_motor_speed(left, fast, 0); 
set_motor_speed(right, stop, 0); 
} 
 
void turn_harshright(void) 
{ 
set_motor_speed(left, stop, 0); 
set_motor_speed(right, fast, 0); 
} 
 
void turn_slightleft(void) 
{ 
set_motor_speed(left, medium, 0); 
set_motor_speed(right, slow, 0); 
} 
 
void spin_left(void) 
{ 
  set_motor_speed(left, rev_fast, 0);  
  set_motor_speed(right, fast, 0);  
} 
 
void turn180(void)
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
  set_motor_speed(left, fast, 0);  
  set_motor_speed(right, fast, 0);  
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
