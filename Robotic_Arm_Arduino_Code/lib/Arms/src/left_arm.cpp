// left_arm.cpp
#include <Arduino.h>
#include "left_arm.h"
#include "smooth.h"
#include <Servo.h>
#include "pins.h"

Servo L_SERVO_MOTOR_BASE_0;
Servo L_SERVO_MOTOR_ARM1_1;
Servo L_SERVO_MOTOR_ARM2_2;
Servo L_SERVO_MOTOR_WRIST_3;
Servo L_SERVO_MOTOR_CLAW_4;

void attach_left_arm_servos(){
  L_SERVO_MOTOR_BASE_0.attach(L_SERVO_PIN_BASE_0);   // Base
  L_SERVO_MOTOR_ARM1_1.attach(L_SERVO_PIN_ARM1_1);   // Arm 1
  L_SERVO_MOTOR_ARM2_2.attach(L_SERVO_PIN_ARM2_2);   // Arm 2
  L_SERVO_MOTOR_WRIST_3.attach(L_SERVO_PIN_WRIST_3); // Wrist
  L_SERVO_MOTOR_CLAW_4.attach(L_SERVO_PIN_CLAW_4);   // Left

}

void left_arm_base(int angle)
{
  // --------------------- For smooth movements ---------------------
  int start_angle = L_SERVO_MOTOR_BASE_0.read();
  int end_angle = angle;
  Servo motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  // L_SERVO_MOTOR_BASE_0.write(angle);
  Serial.print("Base at: ");
  Serial.println(angle);
}

void left_arm_arm1(int angle)
{
  // --------------------- For smooth movements ---------------------
  int start_angle = L_SERVO_MOTOR_ARM1_1.read();
  int end_angle = angle;
  Servo motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  // 180 - Straight up
  // L_SERVO_MOTOR_ARM1_1.write(angle);
  Serial.print("Arm1 at: ");
  Serial.println(angle);
}

void left_arm_arm2(int angle)
{
  // --------------------- For smooth movements ---------------------
  int start_angle = L_SERVO_MOTOR_ARM2_2.read();
  int end_angle = angle;
  Servo motor = L_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  // L_SERVO_MOTOR_ARM2_2.write(angle);
  Serial.print("Arm2 at: ");
  Serial.println(angle);
}

void left_arm_wrist(int angle)
{
  // --------------------- For smooth movements ---------------------
  int start_angle = L_SERVO_MOTOR_WRIST_3.read();
  int end_angle = angle;
  Servo motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  // L_SERVO_MOTOR_WRIST_3.write(angle);
  Serial.print("Wrist at: ");
  Serial.println(angle);
}

void left_arm_claw(int angle)
{
  // --------------------- For smooth movements ---------------------
  int start_angle = L_SERVO_MOTOR_CLAW_4.read();
  int end_angle = angle;
  Servo motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  // L_SERVO_MOTOR_CLAW_4.write(angle);
  Serial.print("Left Claw at: ");
  Serial.println(angle);
}

void left_arm_set_default_position(){
  // servo.read() -> returns the last position value written to the servo

  // get base current position
  int left_arm_base_angle = L_SERVO_MOTOR_BASE_0.read();

  // get arm1 current position
  int left_arm_arm1_angle = L_SERVO_MOTOR_ARM1_1.read();

  // get arm2 current position
  int left_arm_arm2_angle = L_SERVO_MOTOR_ARM2_2.read();

  // get wrist current position
  int left_arm_wrist_angle = L_SERVO_MOTOR_WRIST_3.read();

  // get claw left current position
  int left_arm_claw_angle = L_SERVO_MOTOR_CLAW_4.read();

  // print current arm positions
  Serial.print("Currnt Base angle: ");
  Serial.println(left_arm_base_angle);

  Serial.print("Currnt arm1 angle: ");
  Serial.println(left_arm_arm1_angle);

  Serial.print("Currnt arm2 angle: ");
  Serial.println(left_arm_arm2_angle);

  Serial.print("Currnt wrist angle: ");
  Serial.println(left_arm_wrist_angle);

  Serial.print("Currnt left claw angle: ");
  Serial.println(left_arm_claw_angle);

  // move claw left
  if (left_arm_claw_angle != 140)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_base_angle;
    int end_angle = 140;
    Servo motor = L_SERVO_MOTOR_CLAW_4;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------

    //  L_SERVO_MOTOR_CLAW_4.write(140);
  }

  // move arm1 to 90
  if (left_arm_arm1_angle != 90)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_arm1_angle;
    int end_angle = 90;
    Servo motor = L_SERVO_MOTOR_ARM1_1;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------

    // L_SERVO_MOTOR_ARM1_1.write(90);
  }

  // move arm2 to 90
  if (left_arm_arm2_angle != 90)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_arm2_angle;
    int end_angle = 90;
    Servo motor = L_SERVO_MOTOR_ARM2_2;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------

    // L_SERVO_MOTOR_ARM2_2.write(90);
  }

  // move base to 0
  if (left_arm_base_angle != 0)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_base_angle;
    int end_angle = 0;
    Servo motor = L_SERVO_MOTOR_BASE_0;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------

    // L_SERVO_MOTOR_BASE_0.write(0);
  }

  // move wrist to 180
  if (left_arm_wrist_angle != 0)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_wrist_angle;
    int end_angle = 0;
    Servo motor = L_SERVO_MOTOR_WRIST_3;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------

    //  L_SERVO_MOTOR_WRIST_3.write(0);
  }
}

// Fold 3 -> Bottom Corner
void left_arm_fold3_object(){

  int start_angle;
  int end_angle;
  Servo motor;

  // XII
  // L_SERVO_MOTOR_CLAW_4.write(80); // Left claw
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 80;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_BASE_0.write(85); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 85;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  //  L_SERVO_MOTOR_BASE_0.write(65); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 65;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_ARM1_1.write(15);
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 15;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  //  L_SERVO_MOTOR_ARM2_2.write(105);
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM2_2.read();
  end_angle = 105;
  motor = L_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  //  L_SERVO_MOTOR_WRIST_3.write(180);
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 180;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_BASE_0.write(98); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 98;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_CLAW_4.write(90);
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_WRIST_3.write(0);
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_WRIST_3.write(0); // Wrist
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  Serial.println("hold_object called");
}

// Fold 1 -> Top Left Corner
void left_arm_fold1_object(){

  int start_angle;
  int end_angle;
  Servo motor;

  // L_SERVO_MOTOR_BASE_0.write(140); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 140;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_ARM1_1.write(90); // Arm 1
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_ARM1_1.write(45); // Arm 1
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 45;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_ARM1_1.write(10); // Arm 1
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 10;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_BASE_0.write(108); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 108;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_CLAW_4.write(90); // Left claw
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 180;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // L_SERVO_MOTOR_ARM1_1.write(0); // Arm 2
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  Serial.println("fold_object called");
}

void left_arm_pick_object(){
  // Get in position

  // Hold the object

  // Pick the object

  // Serve the object
}
