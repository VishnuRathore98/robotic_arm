import json
import time

def set_right_arm_base_angle(angle, arduino):
    data = {
        "motor":"r_base",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_arm1_angle(angle, arduino):
    data = {
        "motor":"r_arm1",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_arm2_angle(angle, arduino):
    data = {
        "motor":"r_arm2",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_wrist_angle(angle, arduino):
    data = {
        "motor":"r_wrist",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_claw_angle(angle, arduino):
    data = {
        "motor":"r_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_default_position(arduino):
    data = {
        "motor":"r_set_default_position",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Set default position")

def right_arm_unfold_object(arduino):
    data = {
        "motor":"r_unfold_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Unfold right arm")

def right_arm_fold2_object(arduino):
    data = {
        "motor":"r_fold2_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Fold2 Object")

def right_arm_pick_object(arduino):
    data = {
        "motor":"r_pick_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n' 
    arduino.write(json_str.encode())
    print("Pick Object")

def right_arm_hold_object(arduino):
    data = {
        "motor":"r_hold_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n' 
    arduino.write(json_str.encode())
 
 def set_right_arm_hold_angle(angle, arduino):
    data = {
        "motor":"r_hold_angle",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n' 
    arduino.write(json_str.encode())