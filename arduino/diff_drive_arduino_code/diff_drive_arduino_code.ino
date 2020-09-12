#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>

#define led_pin 13
#define step_pin_right 11
#define direction_pin_right 10
#define step_pin_left 9
#define direction_pin_left 8
#define enable_pin 6

AccelStepper right_motor(AccelStepper::DRIVER, step_pin_right, direction_pin_right);
AccelStepper left_motor(AccelStepper::DRIVER, step_pin_left, direction_pin_left);
MultiStepper steppers;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(led_pin, OUTPUT);
//  right_motor.setEnablePin(enable_pin);
//  right_motor.setPinsInverted(false, false, true);  right_motor.setMaxSpeed(36000);
  right_motor.setMaxSpeed(3600);
  right_motor.setSpeed(300);
//  right_motor.setAcceleration(1200);
  left_motor.setMaxSpeed(3600);
  left_motor.setSpeed(300);
//  left_motor.setAcceleration(1200);
  right_motor.enableOutputs();
  left_motor.enableOutputs();

//  steppers.addStepper(right_motor);
//  steppers.addStepper(left_motor);
}

int extract_angle(String cmd){
  int len = cmd.length();
  String angle_str = cmd.substring(1,len);
  int angle = angle_str.toInt();
  return angle;
}

void loop() {
  left_motor.runSpeed();
  right_motor.runSpeed();
  if(Serial.available() > 0)
  { 
    String command = Serial.readStringUntil('\n');
    Serial.println(command);  
    if(command[0] == 'T'){
      digitalWrite(led_pin, HIGH);
      int move_angle = extract_angle(command);
      left_motor.setSpeed(move_angle);
      right_motor.setSpeed(move_angle);
      Serial.println("Moving by --> " + String(move_angle) + " degrees");
    }

    if(command[0] == 'S'){
      digitalWrite(led_pin, LOW);
    }
  }
  // put your main code here, to run repeatedly:
}
