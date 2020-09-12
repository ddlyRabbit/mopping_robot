/*
A library to drive two steppers in velocity control mode

Initialize with steps/radian
motor_a step --> 9
motor_a dir --> 8
motor_b step --> 10
motor_b dir --> 11

Example
#include "timer_one_stepper_drive.h"
const float steps_per_radian = 1018.6;
void setup() {
  drive.initialize(steps_per_radian);
  drive.set_vel(0,0);
  drive.enable();
}

void loop(){
 // use drive.set_vel() to keep updating the velocity
 // use drive._omega_max = 3.0 to set max omega limit
}

*/

#ifndef timer_one_stepper_drive_h
#define timer_one_stepper_drive_h

#include "Arduino.h"

class DualDrive
{
	public:
		void initialize(float steps_per_radian);
		void set_vel(float vel_a, float vel_b);
    int  calc_half_period(float omega);
		void enable_a();
		void disable_a();
		void enable_b();
		void disable_b();
		float _steps_per_radian;
		float _half_period_a = 5000;
		float _half_period_b = 5000;
    float _omega_max = 10.0;	
};

extern DualDrive drive;

#endif
