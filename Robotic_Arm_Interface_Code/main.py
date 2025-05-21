import time
import gradio as gr
import serial as sr
import json

try:
    arduino = sr.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=.1)
    time.sleep(2)
except Exception as e:
    print("port ttyUSB0 not available")
    try:
        arduino = sr.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)
        time.sleep(2)
    except:
        print("port ttyACM0 not available")

def set_left_arm_base_angle(angle):
    data = {
        "motor":"l_base",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_arm1_angle(angle):
    data = {
        "motor":"l_arm1",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_arm2_angle(angle):
    data = {
        "motor":"l_arm2",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_wrist_angle(angle):
    data = {
        "motor":"l_wrist",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_left_claw_angle(angle):
    data = {
        "motor":"l_left_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_right_claw_angle(angle):
    data = {
        "motor":"l_right_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_default_position():
    data = {
        "motor":"l_set_default_position",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Set default position")

def left_arm_pick_object():
    data = {
        "motor":"l_pick_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Pick Object")

def left_arm_drop_object():
    data = {
        "motor":"l_drop_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Drop Object")
    
def left_arm_hold_leaf():
    ...

def left_arm_fold_leaf():
    ...

def left_arm_leave_leaf():
    ...

# ------------------------------------------Right Arm Code---------------------------------

def set_right_arm_base_angle(angle):
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

def set_right_arm_arm1_angle(angle):
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

def set_right_arm_arm2_angle(angle):
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

def set_right_arm_wrist_angle(angle):
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

def set_right_arm_left_claw_angle(angle):
    data = {
        "motor":"r_left_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_right_claw_angle(angle):
    data = {
        "motor":"r_right_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_arm_default_position():
    data = {
        "motor":"r_set_default_position",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Set default position")

def right_arm_pick_object():
    data = {
        "motor":"r_pick_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Pick Object")

def right_arm_drop_object():
    data = {
        "motor":"r_drop_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Drop Object")

def right_arm_hold_leaf():
    ...

def right_arm_fold_leaf():
    ...

def right_arm_leave_leaf():
    ...


with gr.Blocks() as app:
    with gr.Row():
        with gr.Column():
            gr.Markdown("# **Left Arm**")
        
            left_arm_input_base = gr.Text(label="Base")
            left_arm_button_base = gr.Button("Set Base")
        
            left_arm_input_arm1 = gr.Text(label="Arm1")
            left_arm_button_arm1 = gr.Button("Set Arm1")
        
            left_arm_input_arm2 = gr.Text(label="Arm2")
            left_arm_button_arm2 = gr.Button("Set Arm2")
        
            left_arm_input_wrist = gr.Text(label="Wrist")
            left_arm_button_wrist = gr.Button("Set Wrist")
        
            left_arm_input_claw_left = gr.Text(label="Left Claw")
            left_arm_button_claw_left = gr.Button("Set Left Claw")
        
            left_arm_input_claw_right = gr.Text(label="Right Claw")
            left_arm_button_claw_right = gr.Button("Set Right Claw")
        
            left_arm_button_set_default_position = gr.Button("Set Default Position")
            left_arm_button_pick_object = gr.Button("Pick Object")
            left_arm_button_drop_object = gr.Button("Drop Object")

            left_arm_button_base.click(fn=set_left_arm_base_angle, inputs=left_arm_input_base)
            left_arm_button_arm1.click(fn=set_left_arm_arm1_angle, inputs=left_arm_input_arm1)
            left_arm_button_arm2.click(fn=set_left_arm_arm2_angle, inputs=left_arm_input_arm2)
            left_arm_button_wrist.click(fn=set_left_arm_wrist_angle, inputs=left_arm_input_wrist)
            left_arm_button_claw_left.click(fn=set_left_arm_left_claw_angle, inputs=left_arm_input_claw_left)
            left_arm_button_claw_right.click(fn=set_left_arm_right_claw_angle, inputs=left_arm_input_claw_right)
            left_arm_button_set_default_position.click(fn=set_left_arm_default_position)
            left_arm_button_pick_object.click(fn=left_arm_pick_object)
            left_arm_button_drop_object.click(fn=left_arm_drop_object)
            
        with gr.Column():
            gr.Markdown("# **Right Arm**")
        
            right_arm_input_base = gr.Text(label="Base")
            right_arm_button_base = gr.Button("Set Base")
        
            right_arm_input_arm1 = gr.Text(label="Arm1")
            right_arm_button_arm1 = gr.Button("Set Arm1")
        
            right_arm_input_arm2 = gr.Text(label="Arm2")
            right_arm_button_arm2 = gr.Button("Set Arm2")
        
            right_arm_input_wrist = gr.Text(label="Wrist")
            right_arm_button_wrist = gr.Button("Set Wrist")
        
            right_arm_input_claw_left = gr.Text(label="Left Claw")
            right_arm_button_claw_left = gr.Button("Set Left Claw")
        
            right_arm_input_claw_right = gr.Text(label="Right Claw")
            right_arm_button_claw_right = gr.Button("Set Right Claw")
        
            right_arm_button_set_default_position = gr.Button("Set Default Position")
            right_arm_button_pick_object = gr.Button("Pick Object")
            right_arm_button_drop_object = gr.Button("Drop Object")

            right_arm_button_base.click(fn=set_right_arm_base_angle, inputs=right_arm_input_base)
            right_arm_button_arm1.click(fn=set_right_arm_arm1_angle, inputs=right_arm_input_arm1)
            right_arm_button_arm2.click(fn=set_right_arm_arm2_angle, inputs=right_arm_input_arm2)
            right_arm_button_wrist.click(fn=set_right_arm_wrist_angle, inputs=right_arm_input_wrist)
            right_arm_button_claw_left.click(fn=set_right_arm_left_claw_angle, inputs=right_arm_input_claw_left)
            right_arm_button_claw_right.click(fn=set_right_arm_right_claw_angle, inputs=right_arm_input_claw_right)
            right_arm_button_set_default_position.click(fn=set_right_arm_default_position)
            right_arm_button_pick_object.click(fn=right_arm_pick_object)
            right_arm_button_drop_object.click(fn=right_arm_drop_object)
app.launch()