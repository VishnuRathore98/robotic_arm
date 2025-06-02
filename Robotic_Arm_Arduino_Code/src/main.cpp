#include <Arduino.h>
#include <ArduinoJson.h>
#include "left_arm.cpp"
#include "right_arm.cpp"

#define RESET_ARMS_BUTTON 0
#define FOLD_OBJECT_BUTTON 1 

int current_reset_button_state = LOW;
int last_reset_button_state = LOW;

int current_fold_object_button_state = LOW;
int last_fold_object_button_state = LOW;

void setup()
{
  Serial.begin(9600);

  pinMode(RESET_ARMS_BUTTON, INPUT_PULLUP);
  pinMode(FOLD_OBJECT_BUTTON, INPUT_PULLUP);
  
  attach_left_arm_servos();
  attach_right_arm_servos();
  right_arm_set_default_position();
  left_arm_set_default_position();
}

void loop(){

  current_reset_button_state = digitalRead(RESET_ARMS_BUTTON);
  current_fold_object_button_state = digitalRead(FOLD_OBJECT_BUTTON);
  
if (current_fold_object_button_state == HIGH && last_fold_object_button_state == LOW){
  delay(200);
  left_arm_fold1_object();
  delay(200);
  right_arm_fold2_object();
  delay(200);
  left_arm_fold3_object();
  delay(200);
  right_arm_unfold_object();
  delay(200);
  right_arm_hold_object();
  delay(200);
  left_arm_unfold();
  delay(200);
  left_arm_fold4_object();
  delay(200);
  right_arm_pick_object();
  delay(200);  
  left_arm_set_default_position();
  delay(200);
}else if (current_reset_button_state == HIGH && last_reset_button_state == LOW)
  {
    delay(200);
    left_arm_set_default_position();
    delay(200);
    right_arm_set_default_position();
    delay(200);
  }
  
  last_fold_object_button_state = current_fold_object_button_state;
  last_reset_button_state = current_reset_button_state;
  
  if (Serial.available() != 0)
  {
    String data = Serial.readStringUntil('\n');
    data.trim();

    StaticJsonDocument<100> doc;
    DeserializationError error = deserializeJson(doc, data);

    if (error)
    {
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

    else if (motor == "l_fold_angle")
      left_arm_fold_angle(angle.toInt());

    else if (motor == "l_set_default_position")
      left_arm_set_default_position();

    else if (motor == "l_fold3_object")
      left_arm_fold3_object();

    else if (motor == "l_fold1_object")
      left_arm_fold1_object();

    else if (motor == "l_fold4_object")
      left_arm_fold4_object();

    else if (motor == "l_unfold_arm")
      left_arm_unfold();

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

    else if (motor == "r_hold_angle")
      right_arm_hold_angle(angle.toInt());

    else if (motor == "r_set_default_position")
      right_arm_set_default_position();

    else if (motor == "r_unfold_object")
      right_arm_unfold_object();

    else if (motor == "r_fold2_object")
      right_arm_fold2_object();

    else if (motor == "r_hold_object")
      right_arm_hold_object();
    
    else if (motor == "r_pick_object")
      right_arm_pick_object();
    

    else
    {
      Serial.println("Invalid command received");
      return;
    }
  }

}

void all_folds_object(){
  left_arm_fold1_object();
  right_arm_fold2_object();
  left_arm_fold3_object();
  right_arm_unfold_object();
  right_arm_hold_object();
  left_arm_unfold();
  left_arm_fold4_object();
  right_arm_pick_object();
}