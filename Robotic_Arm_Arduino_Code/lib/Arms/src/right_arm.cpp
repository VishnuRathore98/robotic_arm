// right_arm.cpp
#include <Arduino.h>
#include <Servo.h>
#include "smooth.h"
#include "right_arm.h"
#include "pins.h"

Servo R_SERVO_MOTOR_BASE_0;
Servo R_SERVO_MOTOR_ARM1_1;
Servo R_SERVO_MOTOR_ARM2_2;
Servo R_SERVO_MOTOR_WRIST_3;
Servo R_SERVO_MOTOR_CLAW_4;

void attach_right_arm_servos(){
R_SERVO_MOTOR_BASE_0.attach(R_SERVO_PIN_BASE_0);   // Base
R_SERVO_MOTOR_ARM1_1.attach(R_SERVO_PIN_ARM1_1);   // Arm 1
R_SERVO_MOTOR_ARM2_2.attach(R_SERVO_PIN_ARM2_2);   // Arm 2
R_SERVO_MOTOR_WRIST_3.attach(R_SERVO_PIN_WRIST_3); // Wrist
R_SERVO_MOTOR_CLAW_4.attach(R_SERVO_PIN_CLAW_4);   // Left

}

void right_arm_base(int angle){
  int start_angle = R_SERVO_MOTOR_BASE_0.read();
  int end_angle = angle;
  Servo motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  Serial.print("Base at: ");
  Serial.println(angle);
}

void right_arm_arm1(int angle){
  // 180 - Straight up
  // R_SERVO_MOTOR_ARM1_1.write(angle);
  // --------------------- For smooth movements ---------------------
  int start_angle = R_SERVO_MOTOR_ARM1_1.read();
  int end_angle = angle;
  Servo motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  Serial.print("Arm1 at: ");
  Serial.println(angle);
}

void right_arm_arm2(int angle){

  // R_SERVO_MOTOR_ARM2_2.write(angle);
  // --------------------- For smooth movements ---------------------
  int start_angle = R_SERVO_MOTOR_ARM2_2.read();
  int end_angle = angle;
  Servo motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  Serial.print("Arm2 at: ");
  Serial.println(angle);
}

void right_arm_wrist(int angle){

  // R_SERVO_MOTOR_WRIST_3.write(angle);
  // --------------------- For smooth movements ---------------------
  int start_angle = R_SERVO_MOTOR_WRIST_3.read();
  int end_angle = angle;
  Servo motor = R_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  Serial.print("Wrist at: ");
  Serial.println(angle);
}

void right_arm_claw(int angle){

  // R_SERVO_MOTOR_CLAW_4.write(angle);
  // --------------------- For smooth movements ---------------------
  int start_angle = R_SERVO_MOTOR_CLAW_4.read();
  int end_angle = angle;
  Servo motor = R_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------
  Serial.print("Left Claw at: ");
  Serial.println(angle);
}

void right_arm_set_default_position(){
  // servo.read() -> returns the last position value written to the servo

  // get base current position
  int right_arm_base_angle = R_SERVO_MOTOR_BASE_0.read();

  // get arm1 current position
  int right_arm_arm1_angle = R_SERVO_MOTOR_ARM1_1.read();

  // get arm2 current position
  int right_arm_arm2_angle = R_SERVO_MOTOR_ARM2_2.read();

  // get wrist current position
  int right_arm_wrist_angle = R_SERVO_MOTOR_WRIST_3.read();

  // get claw left current position
  int right_arm_claw_angle = R_SERVO_MOTOR_CLAW_4.read();

  // print current arm positions
  Serial.print("Currnt Base angle: ");
  Serial.println(right_arm_base_angle);

  Serial.print("Currnt arm1 angle: ");
  Serial.println(right_arm_arm1_angle);

  Serial.print("Currnt arm2 angle: ");
  Serial.println(right_arm_arm2_angle);

  Serial.print("Currnt wrist angle: ");
  Serial.println(right_arm_wrist_angle);

  Serial.print("Currnt left angle: ");
  Serial.println(right_arm_claw_angle);

  // move claw left to 90
  if (right_arm_claw_angle != 30)
  {

    //  R_SERVO_MOTOR_CLAW_4.write(30);
    // --------------------- For smooth movements ---------------------
    int start_angle = right_arm_claw_angle;
    int end_angle = 30;
    Servo motor = R_SERVO_MOTOR_CLAW_4;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------
  }

  // move arm1 to 90
  if (right_arm_arm1_angle != 90)
  {

    // R_SERVO_MOTOR_ARM1_1.write(90);
    // --------------------- For smooth movements ---------------------
    int start_angle = right_arm_arm1_angle;
    int end_angle = 90;
    Servo motor = R_SERVO_MOTOR_ARM1_1;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------
  }

  // move arm2 to 90
  if (right_arm_arm2_angle != 90)
  {

    // R_SERVO_MOTOR_ARM2_2.write(90);
    // --------------------- For smooth movements ---------------------
    int start_angle = right_arm_arm2_angle;
    int end_angle = 90;
    Servo motor = R_SERVO_MOTOR_ARM2_2;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------
  }

  // move base to 0
  if (right_arm_base_angle != 0)
  {

    //  R_SERVO_MOTOR_BASE_0.write(0);
    // --------------------- For smooth movements ---------------------
    int start_angle = right_arm_base_angle;
    int end_angle = 0;
    Servo motor = R_SERVO_MOTOR_BASE_0;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------
  }

  // move wrist to 180
  if (right_arm_wrist_angle != 180)
  {
    //  R_SERVO_MOTOR_WRIST_3.write(180);
    // --------------------- For smooth movements ---------------------
    int start_angle = right_arm_wrist_angle;
    int end_angle = 180;
    Servo motor = R_SERVO_MOTOR_WRIST_3;
    rotate_smoothly(start_angle, end_angle, motor);
    // -----------------------------------------------------------------
  }
}

// Fold 4 -> Hold the folds
void right_arm_fold4_object(){
  int start_angle;
  int end_angle;
  Servo motor;

  // R_SERVO_MOTOR_ARM2_2.write(50);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 50;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_BASE_0.write(20);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 20;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_ARM1_1.write(90);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_BASE_0.write(40);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 40;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_ARM2_2.write(45);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 45;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_ARM2_2.write(15);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 15;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_ARM2_2.write(0);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 0;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_ARM1_1.write(105);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 105;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  Serial.println("hold_object called");
}

// Fold 2 -> Top Right Corner
void right_arm_fold2_object(){

  int start_angle;
  int end_angle;
  Servo motor;

  // R_SERVO_MOTOR_CLAW_4.write(80); // Left claw added
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_CLAW_4.read();
  end_angle = 80;
  motor = R_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // VII
  // R_SERVO_MOTOR_BASE_0.write(25); // Base
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 25;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // VIII
  // R_SERVO_MOTOR_ARM1_1.write(145); // Arm 1 140->145
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 145;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // IX
  // R_SERVO_MOTOR_ARM2_2.write(58); // Arm 2 55->45->40
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 50;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_BASE_0.write(42);
  // --------------------- For smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 45;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  // -----------------------------------------------------------------

  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 60;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);

  // -----------------------------------------------------------------

  // R_SERVO_MOTOR_WRIST_3.write(0);
  // --------------------- F/* code */or smooth movements ---------------------
  start_angle = R_SERVO_MOTOR_WRIST_3.read();
  end_angle = 0;
  motor = R_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor);
  // -----------------------------------------------------------------

  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 58;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor);

  Serial.println("fold_object called");
}

// Pick and Serve
void right_arm_pick_object(){
  int start_angle;
  int end_angle;
  Servo motor;

  // Get in position
  
  // Set base
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Set Arm1
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Set Arm2
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 20;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);


  // Set Claw
  start_angle = R_SERVO_MOTOR_CLAW_4.read();
  end_angle = 30;
  motor = R_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Hold the object

  //Hold

    // Set Arm1
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Set Arm2
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 0;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 10;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  start_angle = R_SERVO_MOTOR_CLAW_4.read();
  end_angle = 70;
  motor = R_SERVO_MOTOR_CLAW_4;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Pick the object

  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 20;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Serve the object


    // Set Arm1
  start_angle = R_SERVO_MOTOR_ARM1_1.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM1_1;
  rotate_smoothly(start_angle, end_angle, motor, 10);

  // Set Arm2
  start_angle = R_SERVO_MOTOR_ARM2_2.read();
  end_angle = 90;
  motor = R_SERVO_MOTOR_ARM2_2;
  rotate_smoothly(start_angle, end_angle, motor, 10);


  // Set base
  start_angle = R_SERVO_MOTOR_BASE_0.read();
  end_angle = 180;
  motor = R_SERVO_MOTOR_BASE_0;
  rotate_smoothly(start_angle, end_angle, motor, 10);


  // Set Wrist
  start_angle = R_SERVO_MOTOR_WRIST_3.read();
  end_angle = 0;
  motor = R_SERVO_MOTOR_WRIST_3;
  rotate_smoothly(start_angle, end_angle, motor, 10);
  
}
