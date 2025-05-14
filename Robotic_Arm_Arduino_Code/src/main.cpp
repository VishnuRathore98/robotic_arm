#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN_BASE_0 3  // Base 0-180 is possible 
#define SERVO_PIN_ARM1_1 5  // Arm1 Do not go below 50 degree (50-180)
#define SERVO_PIN_ARM2_2 6  // Arm2 0-180 is possible 
#define SERVO_PIN_WRIST_3 9   // Wrist 0-180
#define SERVO_PIN_LEFT_CLAW_4 10 // Left Claw 0-180
#define SERVO_PIN_RIGHT_CLAW_5 11  // Right Claw 0-180

int angle;

Servo SERVO_MOTOR_BASE_0;
Servo SERVO_MOTOR_ARM1_1;
Servo SERVO_MOTOR_ARM2_2;
Servo SERVO_MOTOR_WRIST_3;
Servo SERVO_MOTOR_LEFT_CLAW_4;
Servo SERVO_MOTOR_RIGHT_CLAW_5;

void base(int angle);
void arm1(int angle);
void arm2(int angle);
void wrist(int angle);
void left_claw(int angle);
void right_claw(int angle);

void setup(){
  Serial.begin(9600);
  // SERVO_MOTOR_BASE_0.attach(SERVO_PIN_BASE_0); // Base
  // SERVO_MOTOR_ARM1_1.attach(SERVO_PIN_ARM1_1); // Arm 1
  SERVO_MOTOR_ARM2_2.attach(SERVO_PIN_ARM2_2); // Arm 2
  // SERVO_MOTOR_WRIST_3.attach(SERVO_PIN_WRIST_3); // Wrist
  // SERVO_MOTOR_LEFT_CLAW_4.attach(SERVO_PIN_LEFT_CLAW_4); // Left
  // SERVO_MOTOR_RIGHT_CLAW_5.attach(SERVO_PIN_RIGHT_CLAW_5); // Right

  // base(0); 
  // arm1(180); //Straight up
  arm2(90);
  // wrist(90);  // Wrist
  // left_claw(60); // Left
  // right_claw(125); // Right

}

void loop(){
  // while (!Serial.available());
  // if (Serial.available()!=0){
  // angle = Serial.readString().toInt();
  // Serial.println(angle);
  // arm2(angle);
  // }
}

void base(int angle){
  SERVO_MOTOR_BASE_0.write(angle);
}

void arm1(int angle){
  // 180 - Straight up
  SERVO_MOTOR_ARM1_1.write(angle);
}

void arm2(int angle){
  SERVO_MOTOR_ARM2_2.attach(SERVO_PIN_ARM2_2);
  SERVO_MOTOR_ARM2_2.write(angle);
}

void wrist(int angle){
  SERVO_MOTOR_WRIST_3.write(angle);
}

void left_claw(int angle){
  SERVO_MOTOR_LEFT_CLAW_4.write(angle);
}

void right_claw(int angle){
  SERVO_MOTOR_RIGHT_CLAW_5.write(angle);
}