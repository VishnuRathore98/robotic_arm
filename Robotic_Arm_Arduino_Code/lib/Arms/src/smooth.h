// smoothify.h
#ifndef SMOOTH_H
#define SMOOTH_H


#include <Servo.h>

void rotate_smoothly(int start_angle, int end_angle, Servo& motor, int wait=4);

#endif