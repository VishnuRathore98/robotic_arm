// smoothify.cpp
#include <Servo.h>
#include <Arduino.h>
#include "smooth.h"

void rotate_smoothly(int start_angle, int end_angle, Servo& motor, int wait)
{

  if (start_angle > end_angle)
  {
    Serial.println("---Start angle is greater than End angle---");
    Serial.print("Start angle: ");
    Serial.println(start_angle);
    Serial.print("End angle: ");
    Serial.println(end_angle);
    for (int i = start_angle; i >= end_angle; i--)
    {
      Serial.println(i);

      motor.write(i);
      delay(wait);
    }
  }

else if (start_angle < end_angle)
  { Serial.println("---Start angle is less than End angle---");
    Serial.print("Start angle: ");
    Serial.println(start_angle);
    Serial.print("End angle: ");
    Serial.println(end_angle);

    for (int i = start_angle; i <= end_angle; i++)
    {
      Serial.println(i);
      motor.write(i);
      delay(wait);
    }
  }
}