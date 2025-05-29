import time
import gradio as gr
import serial as sr
import json

try:
    arduino = sr.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=.1)
    time.sleep(2)
    print("Connected to USB0 port")
except Exception as e:
    print("port ttyUSB0 not available")
    try:
        arduino = sr.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)
        time.sleep(2)
        print("Connected to ACM0 port")
    except:
        print("port ttyACM0 not available")
        try:
            arduino = sr.Serial(port='/dev/ttyACM1', baudrate=9600, timeout=.1)
            time.sleep(2)
            print("Connected to ACM1 port")
        except:
            print("port ttyACM1 not available")
            try:
                arduino = sr.Serial(port='/dev/ttyACM2', baudrate=9600, timeout=.1)
                time.sleep(2)
                print("Connected to ACM2 port")
            except:
                print("port ttyACM2 not available")
                
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
    print("Left arm arm2 clicked")
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
    print("wrist button clicked: ", json_str) 
    arduino.write(json_str.encode())
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_arm_claw_angle(angle):
    data = {
        "motor":"l_claw",
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

def left_arm_fold3_object():
    data = {
        "motor":"l_fold3_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Fold3 Object")

def left_arm_fold1_object():
    data = {
        "motor":"l_fold1_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Fold1 Object")
    
def left_arm_fold4_object():
    data = {
        "motor":"l_fold4_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Fold4 Object")

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

def set_right_arm_claw_angle(angle):
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

def set_right_arm_default_position():
    data = {
        "motor":"r_set_default_position",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Set default position")

def right_arm_hold_object():
    data = {
        "motor":"r_fold4_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Fold4 Object")

def right_arm_fold2_object():
    data = {
        "motor":"r_fold2_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Fold2 Object")

def right_arm_pick_object():
    data = {
        "motor":"r_pick_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n' 
    arduino.write(json_str.encode())
    print("Pick Object")

def fold_object():
    # left_arm_fold_object()
    # right_arm_fold_object()
    # left_arm_hold_object()
    # right_arm_hold_object()
    ...


with gr.Blocks() as app:
    with gr.Column():
        gr.Markdown("# **Click the button below to fold the object**")
        both_arm_folding = gr.Button("Fold the object")
    
    with gr.Row():
        with gr.Column():
            gr.Markdown("# **Left Arm**")
            with gr.Group():
                left_arm_input_base = gr.Text(label="Base")
                left_arm_button_base = gr.Button("Set Base")
            
                left_arm_input_arm1 = gr.Text(label="Arm1")
                left_arm_button_arm1 = gr.Button("Set Arm1")
            
                left_arm_input_arm2 = gr.Text(label="Arm2")
                left_arm_button_arm2 = gr.Button("Set Arm2")
            
                left_arm_input_wrist = gr.Text(label="Wrist")
                left_arm_button_wrist = gr.Button("Set Wrist")
            
                left_arm_input_claw = gr.Text(label="Claw")
                left_arm_button_claw = gr.Button("Set Claw")
        
            left_arm_button_set_default_position = gr.Button("Set Default Position")
            left_arm_button_fold1_object = gr.Button("Fold 1")
            left_arm_button_fold3_object = gr.Button("Fold 3")
            left_arm_button_fold4_object = gr.Button("Fold 4")

            left_arm_button_base.click(fn=set_left_arm_base_angle, inputs=left_arm_input_base)
            left_arm_button_arm1.click(fn=set_left_arm_arm1_angle, inputs=left_arm_input_arm1)
            left_arm_button_arm2.click(fn=set_left_arm_arm2_angle, inputs=left_arm_input_arm2)
            left_arm_button_wrist.click(fn=set_left_arm_wrist_angle, inputs=left_arm_input_wrist)
            left_arm_button_claw.click(fn=set_left_arm_claw_angle, inputs=left_arm_input_claw)
            left_arm_button_set_default_position.click(fn=set_left_arm_default_position)
            left_arm_button_fold3_object.click(fn=left_arm_fold3_object)
            left_arm_button_fold1_object.click(fn=left_arm_fold1_object)
            left_arm_button_fold4_object.click(fn=left_arm_fold4_object)
            both_arm_folding.click(fn=fold_object)
            
        with gr.Column():
            gr.Markdown("# **Right Arm**")
            with gr.Group():
                right_arm_input_base = gr.Text(label="Base")
                right_arm_button_base = gr.Button("Set Base")
            
                right_arm_input_arm1 = gr.Text(label="Arm1")
                right_arm_button_arm1 = gr.Button("Set Arm1")
            
                right_arm_input_arm2 = gr.Text(label="Arm2")
                right_arm_button_arm2 = gr.Button("Set Arm2")
            
                right_arm_input_wrist = gr.Text(label="Wrist")
                right_arm_button_wrist = gr.Button("Set Wrist")
            
                right_arm_input_claw = gr.Text(label="Claw")
                right_arm_button_claw = gr.Button("Set Claw")
        
            right_arm_button_set_default_position = gr.Button("Set Default Position")
            right_arm_button_fold2_object = gr.Button("Fold 2")
            right_arm_button_fold4_object = gr.Button("Fold 4")
            right_arm_button_pick_object = gr.Button("Pick Object")

            right_arm_button_base.click(fn=set_right_arm_base_angle, inputs=right_arm_input_base)
            right_arm_button_arm1.click(fn=set_right_arm_arm1_angle, inputs=right_arm_input_arm1)
            right_arm_button_arm2.click(fn=set_right_arm_arm2_angle, inputs=right_arm_input_arm2)
            right_arm_button_wrist.click(fn=set_right_arm_wrist_angle, inputs=right_arm_input_wrist)
            right_arm_button_claw.click(fn=set_right_arm_claw_angle, inputs=right_arm_input_claw)
            right_arm_button_set_default_position.click(fn=set_right_arm_default_position)
            right_arm_button_fold4_object.click(fn=right_arm_hold_object)
            right_arm_button_fold2_object.click(fn=right_arm_fold2_object)
            right_arm_button_pick_object.click(fn=right_arm_pick_object)
app.launch()