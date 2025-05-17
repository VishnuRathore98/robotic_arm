#include <Arduino.h>
#include <Servo.h>
#include <ArduinoJson.h>

#define SERVO_PIN_BASE_0 3  // Base 0-180 is possible 
#define SERVO_PIN_ARM1_1 5  // Arm1 Do not go below 50 degree (50-180)
#define SERVO_PIN_ARM2_2 6  // Arm2 0-180 is possible 
#define SERVO_PIN_WRIST_3 9   // Wrist 0-180
#define SERVO_PIN_LEFT_CLAW_4 10 // Left Claw 0-180
#define SERVO_PIN_RIGHT_CLAW_5 11  // Right Claw 0-180

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

void set_default_position();
void pick_object();
void drop_object();

void setup(){
  Serial.begin(9600);
  SERVO_MOTOR_BASE_0.attach(SERVO_PIN_BASE_0); // Base
  SERVO_MOTOR_ARM1_1.attach(SERVO_PIN_ARM1_1); // Arm 1
  SERVO_MOTOR_ARM2_2.attach(SERVO_PIN_ARM2_2); // Arm 2
  SERVO_MOTOR_WRIST_3.attach(SERVO_PIN_WRIST_3); // Wrist
  SERVO_MOTOR_LEFT_CLAW_4.attach(SERVO_PIN_LEFT_CLAW_4); // Left
  SERVO_MOTOR_RIGHT_CLAW_5.attach(SERVO_PIN_RIGHT_CLAW_5); // Right
}

void loop(){
  if (Serial.available()!=0){
    String data = Serial.readStringUntil('\n');
    data.trim();
    
    StaticJsonDocument<100> doc;
    DeserializationError error = deserializeJson(doc, data);

    if(error){
      Serial.println("Json deserialization error");
      Serial.println(error.f_str());
      return;
    }

    String motor = doc["motor"];
    String angle = doc["angle"];
    
    if (motor == "base")
    base(angle.toInt());
    
    else if (motor == "arm1")
    arm1(angle.toInt());
    
    else if (motor == "arm2")
    arm2(angle.toInt());
    
    else if (motor == "wrist")
      wrist(angle.toInt());
    
    else if (motor == "left_claw")
      left_claw(angle.toInt());
    
    else if (motor == "right_claw")
      right_claw(angle.toInt());
    
    else if (motor == "set_default_position")
      set_default_position();
    
    else if (motor == "pick_object")
      pick_object();
    
    else if (motor == "drop_object")
      drop_object();

    else{
        Serial.println("Invalid command received");
        return;
      }
    }

}

void base(int angle){
  SERVO_MOTOR_BASE_0.write(angle);
  Serial.print("Base at: ");
  Serial.println(angle);
}

void arm1(int angle){
  // 180 - Straight up
  SERVO_MOTOR_ARM1_1.write(angle);
  Serial.print("Arm1 at: ");
  Serial.println(angle);
}

void arm2(int angle){
  SERVO_MOTOR_ARM2_2.write(angle);
  Serial.print("Arm2 at: ");
  Serial.println(angle);
}

void wrist(int angle){
  SERVO_MOTOR_WRIST_3.write(angle);
  Serial.print("Wrist at: ");
  Serial.println(angle);
}

void left_claw(int angle){
  SERVO_MOTOR_LEFT_CLAW_4.write(angle);
  Serial.print("Left Claw at: ");
  Serial.println(angle);
}

void right_claw(int angle){
  SERVO_MOTOR_RIGHT_CLAW_5.write(angle);
  Serial.print("Right Claw at: ");
  Serial.println(angle);
}

void set_default_position(){
  // servo.read() -> returns the last position value written to the servo
  
  // get base current position
  int base_angle = SERVO_MOTOR_BASE_0.read();

  // get arm1 current position
  int arm1_angle = SERVO_MOTOR_ARM1_1.read();  

  // get arm2 current position
  int arm2_angle = SERVO_MOTOR_ARM2_2.read();
  
  // get wrist current position
  int wrist_angle = SERVO_MOTOR_WRIST_3.read();

  // get claw left current position
  int left_claw_angle = SERVO_MOTOR_LEFT_CLAW_4.read();

  // get claw right current position
  int right_claw_angle = SERVO_MOTOR_RIGHT_CLAW_5.read();
  
  // print current arm positions
  Serial.print("Currnt Base angle: ");
  Serial.println(base_angle);
  
  Serial.print("Currnt arm1 angle: ");
  Serial.println(arm1_angle);
  
  Serial.print("Currnt arm2 angle: ");
  Serial.println(arm2_angle);     
  
  Serial.print("Currnt wrist angle: ");
  Serial.println(wrist_angle); 
  
  Serial.print("Currnt left angle: ");
  Serial.println(left_claw_angle); 
  
  Serial.print("Currnt right angle: ");
  Serial.println(right_claw_angle);

  // move claw left to 90
      if(left_claw_angle!=90)
       SERVO_MOTOR_LEFT_CLAW_4.write(90);
 delay(200);

  // move claw right to 90
    if(right_claw_angle!=90)
      SERVO_MOTOR_RIGHT_CLAW_5.write(90);
 delay(200);

  // move arm1 to 90
    if(arm1_angle!=90)
        SERVO_MOTOR_ARM1_1.write(90);
  delay(200);
   
  // move arm2 to 90
    if(arm2_angle!=90)
      SERVO_MOTOR_ARM2_2.write(90);
   delay(200);
  
      // move base to 0
    if(base_angle!=0)
       SERVO_MOTOR_BASE_0.write(0);    
    delay(200);
 
  // move wrist to 180
      if(wrist_angle!=180)
       SERVO_MOTOR_WRIST_3.write(180);
     delay(200);

}

void pick_object(){

  SERVO_MOTOR_BASE_0.write(0); // Base
  delay(200);
 SERVO_MOTOR_ARM1_1.write(40); // Arm 1
   delay(200);
SERVO_MOTOR_ARM2_2.write(165); // Arm 2
   delay(200);
SERVO_MOTOR_WRIST_3.write(180); // Wrist
   delay(200);
SERVO_MOTOR_LEFT_CLAW_4.write(115); // Left claw
   delay(200);
SERVO_MOTOR_RIGHT_CLAW_5.write(70); // Right claw
 delay(200);

  Serial.println("pick_object called");
}

void drop_object(){
  
  SERVO_MOTOR_ARM2_2.write(150); // Arm 2
  delay(200);
  SERVO_MOTOR_ARM1_1.write(40); // Arm 1
   delay(200);
SERVO_MOTOR_BASE_0.write(90); // Base
   delay(200);
SERVO_MOTOR_WRIST_3.write(180); // Wrist
   delay(200);
SERVO_MOTOR_LEFT_CLAW_4.write(90); // Left claw
   delay(200);
SERVO_MOTOR_RIGHT_CLAW_5.write(90); // Right claw
 delay(200);

  Serial.println("drop_object called");
}