#include <Arduino.h>
#include <Servo.h>
#include <ArduinoJson.h>
 
// Left Arm
#define L_SERVO_PIN_BASE_0 2  
#define L_SERVO_PIN_ARM1_1 3  
#define L_SERVO_PIN_ARM2_2 4
#define L_SERVO_PIN_WRIST_3 5   
#define L_SERVO_PIN_CLAW_4 6

Servo L_SERVO_MOTOR_BASE_0;
Servo L_SERVO_MOTOR_ARM1_1;
Servo L_SERVO_MOTOR_ARM2_2;
Servo L_SERVO_MOTOR_WRIST_3;
Servo L_SERVO_MOTOR_CLAW_4;

// Right Arm
#define R_SERVO_PIN_BASE_0 8  
#define R_SERVO_PIN_ARM1_1 9  
#define R_SERVO_PIN_ARM2_2 10
#define R_SERVO_PIN_WRIST_3 11  
#define R_SERVO_PIN_CLAW_4 12

Servo R_SERVO_MOTOR_BASE_0;
Servo R_SERVO_MOTOR_ARM1_1;
Servo R_SERVO_MOTOR_ARM2_2;
Servo R_SERVO_MOTOR_WRIST_3;
Servo R_SERVO_MOTOR_CLAW_4;


void left_arm_base(int angle);
void left_arm_arm1(int angle);
void left_arm_arm2(int angle);
void left_arm_wrist(int angle);
void left_arm_claw(int angle);

void left_arm_set_default_position();
void left_arm_hold_object();
void left_arm_fold_object();

// ------------------------------------- Right Arm

void right_arm_base(int angle);
void right_arm_arm1(int angle);
void right_arm_arm2(int angle);
void right_arm_wrist(int angle);
void right_arm_claw(int angle);

void right_arm_set_default_position();
void right_arm_hold_object();
void right_arm_fold_object();


void setup(){
  Serial.begin(9600);

  L_SERVO_MOTOR_BASE_0.attach(L_SERVO_PIN_BASE_0); // Base
  L_SERVO_MOTOR_ARM1_1.attach(L_SERVO_PIN_ARM1_1); // Arm 1
  L_SERVO_MOTOR_ARM2_2.attach(L_SERVO_PIN_ARM2_2); // Arm 2
  L_SERVO_MOTOR_WRIST_3.attach(L_SERVO_PIN_WRIST_3); // Wrist
  L_SERVO_MOTOR_CLAW_4.attach(L_SERVO_PIN_CLAW_4); // Left

  R_SERVO_MOTOR_BASE_0.attach(R_SERVO_PIN_BASE_0); // Base
  R_SERVO_MOTOR_ARM1_1.attach(R_SERVO_PIN_ARM1_1); // Arm 1
  R_SERVO_MOTOR_ARM2_2.attach(R_SERVO_PIN_ARM2_2); // Arm 2
  R_SERVO_MOTOR_WRIST_3.attach(R_SERVO_PIN_WRIST_3); // Wrist
  R_SERVO_MOTOR_CLAW_4.attach(R_SERVO_PIN_CLAW_4); // Left

  right_arm_set_default_position();
  left_arm_set_default_position();

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
    
    else if (motor == "l_claw")
      left_arm_claw(angle.toInt());
    
    else if (motor == "l_set_default_position")
      left_arm_set_default_position();
    
    else if (motor == "l_hold_object")
      left_arm_hold_object();
    
    else if (motor == "l_fold_object")
      left_arm_fold_object();

    // --------- Right Arm Code ---------------

    if (motor == "r_base")
    right_arm_base(angle.toInt());
    
    else if (motor == "r_arm1")
    right_arm_arm1(angle.toInt());
    
    else if (motor == "r_arm2")
    right_arm_arm2(angle.toInt());
    
    else if (motor == "r_wrist")
      right_arm_wrist(angle.toInt());
    
    else if (motor == "r_claw")
      right_arm_claw(angle.toInt());
    
    else if (motor == "r_set_default_position")
      right_arm_set_default_position();
    
    else if (motor == "r_hold_object")
      right_arm_hold_object();
    
    else if (motor == "r_fold_object")
      right_arm_fold_object();

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

void left_arm_claw(int angle){
  L_SERVO_MOTOR_CLAW_4.write(angle);
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
  
  Serial.print("Currnt left angle: ");
  Serial.println(left_arm_claw_angle); 
  

  // move claw left to 90
      if(left_arm_claw_angle!=140)
       L_SERVO_MOTOR_CLAW_4.write(140);
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
      if(left_arm_wrist_angle!=0)
       L_SERVO_MOTOR_WRIST_3.write(0);
     delay(200);

}

void left_arm_hold_object(){
  
  // XII
  L_SERVO_MOTOR_CLAW_4.write(120); // Left claw
  delay(400);
  // XIII
  L_SERVO_MOTOR_BASE_0.write(85); // Base
  delay(400);
  L_SERVO_MOTOR_BASE_0.write(65); // Base
  delay(400);
  // XIV
  L_SERVO_MOTOR_CLAW_4.write(100); // Left claw
  delay(400);

  // R_SERVO_MOTOR_BASE_0.write(30);
  // delay(400);

  L_SERVO_MOTOR_ARM1_1.write(15);
  delay(400);  
  L_SERVO_MOTOR_ARM2_2.write(105);
  delay(400);
  L_SERVO_MOTOR_WRIST_3.write(180);
  delay(400);
  L_SERVO_MOTOR_BASE_0.write(95); // Base
  delay(400);
  L_SERVO_MOTOR_WRIST_3.write(0);
  delay(400);


  // XV
  L_SERVO_MOTOR_WRIST_3.write(0); // Wrist
  delay(400);

  Serial.println("hold_object called");
}

void left_arm_fold_object(){
  // I
  L_SERVO_MOTOR_BASE_0.write(140); // Base
  delay(400);
  // II
  L_SERVO_MOTOR_ARM1_1.write(90); // Arm 1
  delay(400);
  L_SERVO_MOTOR_ARM1_1.write(45); // Arm 1
  delay(400);
  L_SERVO_MOTOR_ARM1_1.write(10); // Arm 1
  delay(400);
  // III
  L_SERVO_MOTOR_BASE_0.write(110); // Base
  delay(400);
  // IV
  L_SERVO_MOTOR_CLAW_4.write(90); // Left claw
  delay(400);
  // V
  L_SERVO_MOTOR_WRIST_3.write(180); // Wrist
  delay(400);
  // VI
  L_SERVO_MOTOR_ARM1_1.write(0); // Arm 2
  delay(400);

  Serial.println("fold_object called");
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

void right_arm_claw(int angle){
  R_SERVO_MOTOR_CLAW_4.write(angle);
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
      if(right_arm_claw_angle!=30)
       R_SERVO_MOTOR_CLAW_4.write(30);
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

void right_arm_hold_object(){

  R_SERVO_MOTOR_BASE_0.write(20);
  delay(400);
  R_SERVO_MOTOR_ARM1_1.write(90);
  delay(400);
  R_SERVO_MOTOR_BASE_0.write(40);
  delay(400);
  R_SERVO_MOTOR_ARM2_2.write(45);
  delay(400);
  R_SERVO_MOTOR_ARM2_2.write(15);
  delay(400);
  R_SERVO_MOTOR_ARM2_2.write(0);
  delay(400);
  R_SERVO_MOTOR_ARM1_1.write(105);
  delay(400);
  
  Serial.println("hold_object called");
}

void right_arm_fold_object(){
  // 
  R_SERVO_MOTOR_CLAW_4.write(80); // Left claw added
  delay(400);

  // VII
  R_SERVO_MOTOR_BASE_0.write(25); // Base
  delay(400);
  // VIII
  R_SERVO_MOTOR_ARM1_1.write(145); // Arm 1 140->145
  delay(400);
  // IX
  R_SERVO_MOTOR_ARM2_2.write(43); // Arm 2 55->45->40
  delay(400);

  // added

  R_SERVO_MOTOR_ARM1_1.write(145); // Arm 1 140->145
  delay(400);
  // IX
  R_SERVO_MOTOR_ARM2_2.write(45); // Arm 2 55->45->40
  delay(400);

  R_SERVO_MOTOR_BASE_0.write(40);
  delay(400);

  R_SERVO_MOTOR_WRIST_3.write(0);
  delay(400);


  // // X
  // R_SERVO_MOTOR_BASE_0.write(50); // Base
  // delay(400);
  // // XI
  // R_SERVO_MOTOR_ARM2_2.write(40); // Arm 2
  // delay(400);

  Serial.println("fold_object called");
}