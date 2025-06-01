import json
import time


def set_left_arm_base_angle(angle, arduino):
    data = {"motor": "l_base", "angle": angle}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response


def set_left_arm_arm1_angle(angle, arduino):
    data = {"motor": "l_arm1", "angle": angle}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response


def set_left_arm_arm2_angle(angle, arduino):
    print("Left arm arm2 clicked")
    data = {"motor": "l_arm2", "angle": angle}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response


def set_left_arm_wrist_angle(angle, arduino):

    data = {"motor": "l_wrist", "angle": angle}
    json_str = json.dumps(data) + "\n"
    print("wrist button clicked: ", json_str)
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response


def set_left_arm_claw_angle(angle, arduino):
    data = {"motor": "l_claw", "angle": angle}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response


def set_left_arm_fold_angle(angle, arduino):
    data = {"motor": "l_fold_angle", "angle": angle}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())


def set_left_arm_default_position(arduino):
    data = {"motor": "l_set_default_position", "angle": "0"}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    print("Set default position")


def left_arm_fold3_object(arduino):
    data = {"motor": "l_fold3_object", "angle": "0"}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    print("Fold3 Object")


def left_arm_fold1_object(arduino):
    data = {"motor": "l_fold1_object", "angle": "0"}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    print("Fold1 Object")


def left_arm_fold4_object(arduino):
    data = {"motor": "l_fold4_object", "angle": "0"}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
    print("Fold4 Object")


def left_arm_unfold_arm(arduino):
    data = {"motor": "l_unfold_arm", "angle": "0"}
    json_str = json.dumps(data) + "\n"
    arduino.write(json_str.encode())
