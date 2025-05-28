// smoothify.h
// #ifndef SMOOTHIFY_H
// #define SMOOTHIFY_H


#include <Servo.h>

void rotate_smoothly(int start_angle, int end_angle, Servo& motor, int wait=10);

// #endif