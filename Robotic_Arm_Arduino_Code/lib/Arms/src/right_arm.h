#ifndef RIGHT_ARM_H
#define RIGHT_ARM_H

void right_arm_base(int angle);
void right_arm_arm1(int angle);
void right_arm_arm2(int angle);
void right_arm_wrist(int angle);
void right_arm_claw(int angle);

void right_arm_set_default_position();
void right_arm_fold4_object();
void right_arm_fold2_object();
void right_arm_pick_object();

#endif