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
Servo L_SERVO_FOURTH_FOLD_CLAW;

void attach_left_arm_servos(){
  L_SERVO_MOTOR_BASE_0.attach(L_SERVO_PIN_BASE_0);   // Base
  L_SERVO_MOTOR_ARM1_1.attach(L_SERVO_PIN_ARM1_1);   // Arm 1
  L_SERVO_MOTOR_ARM2_2.attach(L_SERVO_PIN_ARM2_2);   // Arm 2
  L_SERVO_MOTOR_WRIST_3.attach(L_SERVO_PIN_WRIST_3); // Wrist
  L_SERVO_MOTOR_CLAW_4.attach(L_SERVO_PIN_CLAW_4);   // Left
  L_SERVO_FOURTH_FOLD_CLAW.attach(L_FOURTH_FOLD_CLAW_PIN); //fourth fold claw
}

void left_arm_base(int angle){
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

void left_arm_arm1(int angle){
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

void left_arm_arm2(int angle){
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
 
void left_arm_wrist(int angle){
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

void left_arm_claw(int angle){
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

void left_arm_fold_angle(int angle){
  // Fold the fourth claw 
  int start_angle = L_SERVO_FOURTH_FOLD_CLAW.read();
  int end_angle = angle;
  Servo motor = L_SERVO_FOURTH_FOLD_CLAW;
  rotate_smoothly(start_angle, end_angle, motor, 10);
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

  // get fourth claw position
  int fourth_claw_angle = L_SERVO_FOURTH_FOLD_CLAW.read();

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

  Serial.print("Current fourth claw angle: ");
  Serial.println(fourth_claw_angle);

  // move claw left
  if (left_arm_claw_angle != 95)
  {
    // --------------------- For smooth movements ---------------------
    int start_angle = left_arm_base_angle;
    int end_angle = 95;
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
  if (fourth_claw_angle!=0)
  {
    int start_angle = fourth_claw_angle;
    int end_angle = 0;
    Servo motor = L_SERVO_FOURTH_FOLD_CLAW;
    rotate_smoothly(start_angle, end_angle, motor);
  }
  
}

// Fold 1 -> Top Left Corner
void left_arm_fold1_object(){

  int start_angle;
  int end_angle;
  Servo motor;

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 140;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 40;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // ----------------------------------------------------------------

  // -----------------------------------------------------------------
  start_angle = L_SERVO_MOTOR_ARM2_2.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);

  // ----------------------------------------------------------------

  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);

  // ----------------------------------------------------------------

  
  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 112;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  
  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);


  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 180;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  Serial.println("fold_object called");
}

// Fold 3 -> Bottom Corner
void left_arm_fold3_object(){

  int start_angle;
  int end_angle;
  Servo motor;

// --------------------------- 

  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 45;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);

// ---------------------------

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 85;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);
  // -----------------------------------------------------------------


  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM1_1.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------


  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_ARM2_2.read();
  end_angle = 90;
  motor = L_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 45;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 180;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor, 10);
  // -----------------------------------------------------------------


  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_BASE_0.read();
  end_angle = 100;
  motor = L_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor,10);
  // -----------------------------------------------------------------

  start_angle = L_SERVO_MOTOR_CLAW_4.read();
  end_angle = 80;
  motor = L_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor,10);

  // --------------------- For smooth movements ---------------------
  start_angle = L_SERVO_MOTOR_WRIST_3.read();
  end_angle = 0;
  motor = L_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor,10);
  // -----------------------------------------------------------------

  Serial.println("hold_object called");
}

// Fold 4 -> Middle fold pending
void left_arm_fold4_object(){
  int start_angle;
  int end_angle;
  Servo motor;

  start_angle = L_SERVO_FOURTH_FOLD_CLAW.read();
  end_angle = 45;
  motor = L_SERVO_FOURTH_FOLD_CLAW;
  rotate_smoothly(start_angle, end_angle, motor,10);

  start_angle = L_SERVO_FOURTH_FOLD_CLAW.read();
  end_angle = 90;
  motor = L_SERVO_FOURTH_FOLD_CLAW;
  rotate_smoothly(start_angle, end_angle, motor,10);

  start_angle = L_SERVO_FOURTH_FOLD_CLAW.read();
  end_angle = 135;
  motor = L_SERVO_FOURTH_FOLD_CLAW;
  rotate_smoothly(start_angle, end_angle, motor,10);
}

void left_arm_unfold(){
  int start_angle;
  int end_angle;
  Servo motor;

  // Fold the Arm2 
  start_angle = L_SERVO_MOTOR_ARM2_2.read();
  end_angle = 45;
  motor = L_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  left_arm_set_default_position();
}
