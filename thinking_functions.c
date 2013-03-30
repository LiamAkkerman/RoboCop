#include "../functions/thinking_functions.h"
#include <trig.h>
#define unsigned int Speed = 333;//in metre per 10 seconds (10*(m/s))
#define unsigned char Laser_distance = 18;//this is a guess

unsigned int Dist_to_TCY(unsigned int dist)
{
	return((2500000*dist)/Speed);
}

unsigned int TCY_dist_Dist(unsigned int tcy)
{
	return((Speed*tcy)/2500000);
}

void Travel_for_Distance(unsigned int dist)
{
	While(ReadTimer0() >= (Dist_to_TCY(dist));
}

unsigned char Mirrored_Sensors (unsigned char input_binary)
{
	unsigned char return_binary;
	
	if();
}

void Think_Turn_Angle(void) //problems: doesnt identify corners but needs to start with 0b0011x or 0bx1100
							//depends on being pretty striaght
							//for turns of larger then 90 deg it cant be seeing 0b0111x or 0bx1110
{
	unsigned int distance_traveled;
	unsigned char turn_angle;

	while(1)
	{
		if (SeeLine.b.Center == 0)//start when SeeLine.b.Center turns off
		{
			WriteTimer0(0); //clear the timer
			while((SeeLine.b.CntRight || SeeLine.b.CntLeft) == 1);//dont change during this time
			distance_travled = TCY_to_Dist(ReadTimer0());
			turn_angel=atan(distance_traveld/Laser_distance);
			//reverse
			Travel_for_Distance(distance_traveled);
			//need function for turn for paticular angle
			return(void);
		}
		if ((SeeLine.b.CntRight && SeeLine.b.CntLeft) == 0)//start when SeeLine.b.Center turns off
		{
			WriteTimer0(0); //clear the timer
			while(SeeLine.b.Center == 1);//dont change during this time
			distance_travled = TCY_to_Dist(ReadTimer0());
			turn_angel=atan(Laser_distance/distance_traveled);
			//reverse
			Travel_for_Distance(distance_traveled);
			Turn_for_Angle(turn_angle);//need function for turn for paticular angle
			return(void);
		}
	}
}