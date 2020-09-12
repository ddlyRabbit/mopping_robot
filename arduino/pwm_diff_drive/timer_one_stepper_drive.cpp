#include "Arduino.h"
#include "timer_one_stepper_drive.h"

DualDrive drive;

void DualDrive::initialize(float steps_per_radian = 500)
{
  _steps_per_radian = steps_per_radian;

  DDRB = 0b11111111;

  set_vel(0, 0);
  TCNT1 = 0;
  OCR1A = 0;
  OCR1B = 0;
  TIMSK1 = 1 << OCIE1A | 1 << OCIE1B;
  TCCR1B = 1 << CS10;
  sei();
}

void DualDrive::set_vel(float vel_a, float vel_b)
{ 
  if (vel_a == 0.0) {
    disable_a();
  } else if (vel_a > 0) {
    PORTB |= 1 << PINB0; //set direction
    enable_a();
  } else {
    PORTB &= ~(1 << PINB0); //set direction
    enable_a();
  }

  if (vel_b == 0.0) {
    disable_b();
  } else if (vel_b > 0) {
    PORTB |= 1 << PINB3; //set direction
    enable_b();
  } else {
    PORTB &= ~(1 << PINB3); //set direction
    enable_b();
  }
  
  drive._half_period_a = drive.calc_half_period(vel_a);
  drive._half_period_b = drive.calc_half_period(vel_b);
  OCR1A += drive._half_period_a;
  OCR1B += drive._half_period_b;
}

void DualDrive::enable_a()
{
  TCCR1A |= 1 << COM1A0;
}

void DualDrive::disable_a()
{
  TCCR1A &= 0 << COM1A0;
}

void DualDrive::enable_b()
{
  TCCR1A |= 1 << COM1B0;
}

void DualDrive::disable_b()
{
  TCCR1A &= 0 << COM1B0;
}

int DualDrive::calc_half_period(float omega)
{
  omega = abs(omega);
  omega = constrain(omega, 0, _omega_max);
  return 16000000 / (_steps_per_radian * omega * 2);
}


ISR(TIMER1_COMPA_vect)
{
  OCR1A += drive._half_period_a;
}

ISR(TIMER1_COMPB_vect)
{
  OCR1B += drive._half_period_b;
}
