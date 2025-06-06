#include <Arduino.h>
#include <ArduinoJson.h>
#include "left_arm.cpp"
#include "right_arm.cpp"
#include "pins.h"

int current_reset_button_state = LOW;
int last_reset_button_state = LOW;

int current_fold_object_button_state = LOW;
int last_fold_object_button_state = LOW;

void all_folds_object();
void setup()
{
  Serial.begin(9600);

  // LED Pins
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Button Pins
  pinMode(FOLD_OBJECT_BUTTON, INPUT_PULLUP);
  pinMode(RESET_ARMS_BUTTON, INPUT_PULLUP);

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  
  attach_left_arm_servos();
  attach_right_arm_servos();
  left_arm_set_default_position();
  right_arm_set_default_position();
}

void loop(){

  current_reset_button_state = digitalRead(RESET_ARMS_BUTTON);
  current_fold_object_button_state = digitalRead(FOLD_OBJECT_BUTTON);
  // Serial.println(current_reset_button_state);
  // Serial.println(current_fold_object_button_state);

if (current_fold_object_button_state == HIGH && last_fold_object_button_state == LOW){
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
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
  // right_arm_pick_object();
  delay(200);  
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, HIGH);

  }
else if (current_fold_object_button_state == LOW && last_fold_object_button_state == HIGH){
      delay(200);
    left_arm_set_default_position();
    delay(200);
    right_arm_set_default_position();
    delay(200);

    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, HIGH);
}
//   delay(200);
//   left_arm_fold1_object();
//   delay(200);
//   right_arm_fold2_object();
//   delay(200);
//   left_arm_fold3_object();
//   delay(200);
//   right_arm_unfold_object();
//   delay(200);
//   right_arm_hold_object();
//   delay(200);
//   left_arm_unfold();
//   delay(200);
//   left_arm_fold4_object();
//   delay(200);
//   right_arm_pick_object();
//   delay(200);  
//   digitalWrite(LED_YELLOW, LOW);
//   digitalWrite(LED_GREEN, HIGH);
//   }

//   if (current_reset_button_state == LOW && last_reset_button_state == HIGH){
//     delay(200);
//     left_arm_set_default_position();
//     delay(200);
//     right_arm_set_default_position();
//     delay(200);
//  } 
//  if (current_reset_button_state == HIGH && last_reset_button_state == LOW){
//     delay(200);
//     left_arm_set_default_position();
//     delay(200);
//     right_arm_set_default_position();
//     delay(200);
//  }
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

    String action = doc["action"];
    String angle = doc["angle"];

    // ------------ Left Arm Code --------------

    if (action == "l_base")
      left_arm_base(angle.toInt());

    else if (action == "l_arm1")
      left_arm_arm1(angle.toInt());

    else if (action == "l_arm2")
      left_arm_arm2(angle.toInt());

    else if (action == "l_wrist")
      left_arm_wrist(angle.toInt());

    else if (action == "l_claw")
      left_arm_claw(angle.toInt());

    else if (action == "l_fold_angle")
      left_arm_fold_angle(angle.toInt());

    else if (action == "l_set_default_position")
      left_arm_set_default_position();

    else if (action == "l_fold3_object")
      left_arm_fold3_object();

    else if (action == "l_fold1_object")
      left_arm_fold1_object();

    else if (action == "l_fold4_object")
      left_arm_fold4_object();

    else if (action == "l_unfold_arm")
      left_arm_unfold();

    // --------- Right Arm Code ---------------

    if (action == "r_base")
      right_arm_base(angle.toInt());

    else if (action == "r_arm1")
      right_arm_arm1(angle.toInt());

    else if (action == "r_arm2")
      right_arm_arm2(angle.toInt());

    else if (action == "r_wrist")
      right_arm_wrist(angle.toInt());

    else if (action == "r_claw")
      right_arm_claw(angle.toInt());

    else if (action == "r_hold_angle")
      right_arm_hold_angle(angle.toInt());

    else if (action == "r_set_default_position")
      right_arm_set_default_position();

    else if (action == "r_unfold_object")
      right_arm_unfold_object();

    else if (action == "r_fold2_object")
      right_arm_fold2_object();

    else if (action == "r_hold_object")
      right_arm_hold_object();
    
    else if (action == "r_pick_object")
      right_arm_pick_object();
// ------------------------------- All Folds ---------------------------

    else if (action == "all_folds")
      all_folds_object();

    else
    {
      Serial.println("Invalid command received");
      return;
    }
  }

}

void all_folds_object(){
  delay(200);
  digitalWrite(LED_YELLOW,HIGH);
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
  digitalWrite(LED_GREEN,HIGH);
  // right_arm_pick_object();
}