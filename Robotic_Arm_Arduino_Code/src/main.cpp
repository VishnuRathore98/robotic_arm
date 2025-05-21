#include <Arduino.h>
#include <Servo.h>
#include <ArduinoJson.h>

// Right Arm
#define L_SERVO_PIN_BASE_0 2  // Base 0-180 is possible 
#define L_SERVO_PIN_ARM1_1 3  // Base 0-180 is possible 
#define L_SERVO_PIN_ARM2_2 4
#define L_SERVO_PIN_WRIST_3 5   // Wrist 0-180
#define L_SERVO_PIN_LEFT_CLAW_4 6 // Left Claw 0-180
#define L_SERVO_PIN_RIGHT_CLAW_5 7  // Right Claw 0-180

Servo L_SERVO_MOTOR_BASE_0;
Servo L_SERVO_MOTOR_ARM1_1;
Servo L_SERVO_MOTOR_ARM2_2;
Servo L_SERVO_MOTOR_WRIST_3;
Servo L_SERVO_MOTOR_LEFT_CLAW_4;
Servo L_SERVO_MOTOR_RIGHT_CLAW_5;

// Left Arm
#define R_SERVO_PIN_BASE_0 8  // Base 0-180 is possible 
#define R_SERVO_PIN_ARM1_1 9  // Base 0-180 is possible 
#define R_SERVO_PIN_ARM2_2 10
#define R_SERVO_PIN_WRIST_3 11   // Wrist 0-180
#define R_SERVO_PIN_LEFT_CLAW_4 12 // Left Claw 0-180
#define R_SERVO_PIN_RIGHT_CLAW_5 13  // Right Claw 0-180

Servo R_SERVO_MOTOR_BASE_0;
Servo R_SERVO_MOTOR_ARM1_1;
Servo R_SERVO_MOTOR_ARM2_2;
Servo R_SERVO_MOTOR_WRIST_3;
Servo R_SERVO_MOTOR_LEFT_CLAW_4;
Servo R_SERVO_MOTOR_RIGHT_CLAW_5;


void left_arm_base(int angle);
void left_arm_arm1(int angle);
void left_arm_arm2(int angle);
void left_arm_wrist(int angle);
void left_arm_left_claw(int angle);
void left_arm_right_claw(int angle);

void left_arm_set_default_position();
void left_arm_pick_object();
void left_arm_drop_object();

// ------------------------------------- Right Arm

void right_arm_base(int angle);
void right_arm_arm1(int angle);
void right_arm_arm2(int angle);
void right_arm_wrist(int angle);
void right_arm_left_claw(int angle);
void right_arm_right_claw(int angle);

void right_arm_set_default_position();
void right_arm_pick_object();
void right_arm_drop_object();


void setup(){
  Serial.begin(9600);

  L_SERVO_MOTOR_BASE_0.attach(L_SERVO_PIN_BASE_0); // Base
  L_SERVO_MOTOR_ARM1_1.attach(L_SERVO_PIN_ARM1_1); // Arm 1
  L_SERVO_MOTOR_ARM2_2.attach(L_SERVO_PIN_ARM2_2); // Arm 2
  L_SERVO_MOTOR_WRIST_3.attach(L_SERVO_PIN_WRIST_3); // Wrist
  L_SERVO_MOTOR_LEFT_CLAW_4.attach(L_SERVO_PIN_LEFT_CLAW_4); // Left
  L_SERVO_MOTOR_RIGHT_CLAW_5.attach(L_SERVO_PIN_RIGHT_CLAW_5); // Right

  R_SERVO_MOTOR_BASE_0.attach(R_SERVO_PIN_BASE_0); // Base
  R_SERVO_MOTOR_ARM1_1.attach(R_SERVO_PIN_ARM1_1); // Arm 1
  R_SERVO_MOTOR_ARM2_2.attach(R_SERVO_PIN_ARM2_2); // Arm 2
  R_SERVO_MOTOR_WRIST_3.attach(R_SERVO_PIN_WRIST_3); // Wrist
  R_SERVO_MOTOR_LEFT_CLAW_4.attach(R_SERVO_PIN_LEFT_CLAW_4); // Left
  R_SERVO_MOTOR_RIGHT_CLAW_5.attach(R_SERVO_PIN_RIGHT_CLAW_5); // Right
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
    
    // ------------ Left Arm Code --------------

    if (motor == "l_base")
      left_arm_base(angle.toInt());
    
    else if (motor == "l_arm1")
      left_arm_arm1(angle.toInt());
    
    else if (motor == "l_arm2")
      left_arm_arm2(angle.toInt());
    
    else if (motor == "l_wrist")
      left_arm_wrist(angle.toInt());
    
    else if (motor == "l_left_claw")
      left_arm_left_claw(angle.toInt());
    
    else if (motor == "l_right_claw")
      left_arm_right_claw(angle.toInt());
    
    else if (motor == "l_set_default_position")
      left_arm_set_default_position();
    
    else if (motor == "l_pick_object")
      left_arm_pick_object();
    
    else if (motor == "l_drop_object")
      left_arm_drop_object();

    // --------- Right Arm Code ---------------

    if (motor == "r_base")
    right_arm_base(angle.toInt());
    
    else if (motor == "r_arm1")
    right_arm_arm1(angle.toInt());
    
    else if (motor == "r_arm2")
    right_arm_arm2(angle.toInt());
    
    else if (motor == "r_wrist")
      right_arm_wrist(angle.toInt());
    
    else if (motor == "r_left_claw")
      right_arm_left_claw(angle.toInt());
    
    else if (motor == "r_right_claw")
      right_arm_right_claw(angle.toInt());
    
    else if (motor == "r_set_default_position")
      right_arm_set_default_position();
    
    else if (motor == "r_pick_object")
      right_arm_pick_object();
    
    else if (motor == "r_drop_object")
      right_arm_drop_object();

    else{
        Serial.println("Invalid command received");
        return;
      }
    }

}

void left_arm_base(int angle){
  L_SERVO_MOTOR_BASE_0.write(angle);
  Serial.print("Base at: ");
  Serial.println(angle);
}

void left_arm_arm1(int angle){
  // 180 - Straight up
  L_SERVO_MOTOR_ARM1_1.write(angle);
  Serial.print("Arm1 at: ");
  Serial.println(angle);
}

void left_arm_arm2(int angle){
  L_SERVO_MOTOR_ARM2_2.write(angle);
  Serial.print("Arm2 at: ");
  Serial.println(angle);
}

void left_arm_wrist(int angle){
  L_SERVO_MOTOR_WRIST_3.write(angle);
  Serial.print("Wrist at: ");
  Serial.println(angle);
}

void left_arm_left_claw(int angle){
  L_SERVO_MOTOR_LEFT_CLAW_4.write(angle);
  Serial.print("Left Claw at: ");
  Serial.println(angle);
}

void left_arm_right_claw(int angle){
  L_SERVO_MOTOR_RIGHT_CLAW_5.write(angle);
  Serial.print("Right Claw at: ");
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
  int left_arm_left_claw_angle = L_SERVO_MOTOR_LEFT_CLAW_4.read();

  // get claw right current position
  int left_arm_right_claw_angle = L_SERVO_MOTOR_RIGHT_CLAW_5.read();
  
  // print current arm positions
  Serial.print("Currnt Base angle: ");
  Serial.println(left_arm_base_angle);
  
  Serial.print("Currnt arm1 angle: ");
  Serial.println(left_arm_arm1_angle);
  
  Serial.print("Currnt arm2 angle: ");
  Serial.println(left_arm_arm2_angle);     
  
  Serial.print("Currnt wrist angle: ");
  Serial.println(left_arm_wrist_angle); 
  
  Serial.print("Currnt left angle: ");
  Serial.println(left_arm_left_claw_angle); 
  
  Serial.print("Currnt right angle: ");
  Serial.println(left_arm_right_claw_angle);

  // move claw left to 90
      if(left_arm_left_claw_angle!=90)
       L_SERVO_MOTOR_LEFT_CLAW_4.write(90);
      delay(200);

  // move claw right to 90
    if(left_arm_right_claw_angle!=90)
      L_SERVO_MOTOR_RIGHT_CLAW_5.write(90);
 delay(200);

  // move arm1 to 90
    if(left_arm_arm1_angle!=90)
        L_SERVO_MOTOR_ARM1_1.write(90);
  delay(200);
   
  // move arm2 to 90
    if(left_arm_arm2_angle!=90)
      L_SERVO_MOTOR_ARM2_2.write(90);
   delay(200);
  
      // move base to 0
    if(left_arm_base_angle!=0)
       L_SERVO_MOTOR_BASE_0.write(0);    
    delay(200);
 
  // move wrist to 180
      if(left_arm_wrist_angle!=180)
       L_SERVO_MOTOR_WRIST_3.write(180);
     delay(200);

}

void left_arm_pick_object(){

  L_SERVO_MOTOR_BASE_0.write(0); // Base
  delay(200);
  L_SERVO_MOTOR_ARM1_1.write(40); // Arm 1
  delay(200);
  L_SERVO_MOTOR_ARM2_2.write(165); // Arm 2
  delay(200);
  L_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  delay(200);
  L_SERVO_MOTOR_LEFT_CLAW_4.write(115); // Left claw
  delay(200);
  L_SERVO_MOTOR_RIGHT_CLAW_5.write(70); // Right claw
  delay(200);

  Serial.println("pick_object called");
}

void left_arm_drop_object(){
  
  L_SERVO_MOTOR_ARM2_2.write(150); // Arm 2
  delay(200);
  L_SERVO_MOTOR_ARM1_1.write(40); // Arm 1
  delay(200);
  L_SERVO_MOTOR_BASE_0.write(90); // Base
  delay(200);
  L_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  delay(200);
  L_SERVO_MOTOR_LEFT_CLAW_4.write(90); // Left claw
  delay(200);
  L_SERVO_MOTOR_RIGHT_CLAW_5.write(90); // Right claw
  delay(200);

  Serial.println("drop_object called");
}


// ------------------------------ Right Arm


void right_arm_base(int angle){
  R_SERVO_MOTOR_BASE_0.write(angle);
  Serial.print("Base at: ");
  Serial.println(angle);
}

void right_arm_arm1(int angle){
  // 180 - Straight up
  R_SERVO_MOTOR_ARM1_1.write(angle);
  Serial.print("Arm1 at: ");
  Serial.println(angle);
}

void right_arm_arm2(int angle){
  R_SERVO_MOTOR_ARM2_2.write(angle);
  Serial.print("Arm2 at: ");
  Serial.println(angle);
}

void right_arm_wrist(int angle){
  R_SERVO_MOTOR_WRIST_3.write(angle);
  Serial.print("Wrist at: ");
  Serial.println(angle);
}

void right_arm_left_claw(int angle){
  R_SERVO_MOTOR_LEFT_CLAW_4.write(angle);
  Serial.print("Left Claw at: ");
  Serial.println(angle);
}

void right_arm_right_claw(int angle){
  R_SERVO_MOTOR_RIGHT_CLAW_5.write(angle);
  Serial.print("Right Claw at: ");
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
  int right_arm_left_claw_angle = R_SERVO_MOTOR_LEFT_CLAW_4.read();

  // get claw right current position
  int right_arm_right_claw_angle = R_SERVO_MOTOR_RIGHT_CLAW_5.read();
  
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
  Serial.println(right_arm_left_claw_angle); 
  
  Serial.print("Currnt right angle: ");
  Serial.println(right_arm_right_claw_angle);

  // move claw left to 90
      if(right_arm_left_claw_angle!=90)
       R_SERVO_MOTOR_LEFT_CLAW_4.write(90);
      delay(200);

  // move claw right to 90
    if(right_arm_right_claw_angle!=90)
      R_SERVO_MOTOR_RIGHT_CLAW_5.write(90);
 delay(200);

  // move arm1 to 90
    if(right_arm_arm1_angle!=90)
        R_SERVO_MOTOR_ARM1_1.write(90);
  delay(200);
   
  // move arm2 to 90
    if(right_arm_arm2_angle!=90)
      R_SERVO_MOTOR_ARM2_2.write(90);
   delay(200);
  
      // move base to 0
    if(right_arm_base_angle!=0)
       R_SERVO_MOTOR_BASE_0.write(0);    
    delay(200);
 
  // move wrist to 180
      if(right_arm_wrist_angle!=180)
       R_SERVO_MOTOR_WRIST_3.write(180);
     delay(200);

}

void right_arm_pick_object(){

  R_SERVO_MOTOR_BASE_0.write(0); // Base
  delay(200);
  R_SERVO_MOTOR_ARM1_1.write(40); // Arm 1
  delay(200);
  R_SERVO_MOTOR_ARM2_2.write(165); // Arm 2
  delay(200);
  R_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  delay(200);
  R_SERVO_MOTOR_LEFT_CLAW_4.write(115); // Left claw
  delay(200);
  R_SERVO_MOTOR_RIGHT_CLAW_5.write(70); // Right claw
  delay(200);

  Serial.println("pick_object called");
}

void right_arm_drop_object(){
  
  R_SERVO_MOTOR_ARM2_2.write(150); // Arm 2
  delay(200);
  R_SERVO_MOTOR_ARM1_1.write(40); // Arm 1
  delay(200);
  R_SERVO_MOTOR_BASE_0.write(90); // Base
  delay(200);
  R_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  delay(200);
  R_SERVO_MOTOR_LEFT_CLAW_4.write(90); // Left claw
  delay(200);
  R_SERVO_MOTOR_RIGHT_CLAW_5.write(90); // Right claw
  delay(200);

  Serial.println("drop_object called");
}