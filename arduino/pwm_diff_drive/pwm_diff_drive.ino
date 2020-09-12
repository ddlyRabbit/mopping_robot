#include <ros.h>
#include "timer_one_stepper_drive.h"
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;
#define led_pin 13
#define enable_pin 6
const float steps_per_radian = 1018.6;
float wheel_radius = 0.045; // in m
float dist_bwn_wheels = 0.21; // in m

void TwistCallback(const geometry_msgs::Twist& vel)
{
  float left = (2.0 * vel.linear.x - vel.angular.z * dist_bwn_wheels) / (2 * wheel_radius);
  float right = (2.0 * vel.linear.x + vel.angular.z * dist_bwn_wheels) / (2 * wheel_radius);
  drive.set_vel(left,right);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel",TwistCallback);

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  pinMode(enable_pin,OUTPUT);
  
  drive.initialize(steps_per_radian);
  
  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
}
