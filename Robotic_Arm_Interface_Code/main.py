import time
import gradio as gr
import serial as sr
import json

arduino = sr.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)
time.sleep(2)

def set_base_angle(angle):
    data = {
        "motor":"base",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_arm1_angle(angle):
    data = {
        "motor":"arm1",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_arm2_angle(angle):
    data = {
        "motor":"arm2",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_wrist_angle(angle):
    data = {
        "motor":"wrist",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_left_claw_angle(angle):
    data = {
        "motor":"left_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_right_claw_angle(angle):
    data = {
        "motor":"right_claw",
        "angle":angle
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode()) 
    time.sleep(0.2)
    response = arduino.readline().decode().strip()
    print("data sent: ", json_str)
    print("data received: ", response)
    # return response

def set_default_position():
    data = {
        "motor":"set_default_position",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Set default position")

def pick_object():
    data = {
        "motor":"pick_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())   
    print("Pick Object")

def drop_object():
    data = {
        "motor":"drop_object",
        "angle":"0"
    }
    json_str = json.dumps(data)+'\n'
    arduino.write(json_str.encode())
    print("Drop Object")

with gr.Blocks() as app:
    with gr.Row():
        input_base = gr.Text(label="Base")
        button_base = gr.Button("Set Base")
    with gr.Row():
        input_arm1 = gr.Text(label="Arm1")
        button_arm1 = gr.Button("Set Arm1")
    with gr.Row():
        input_arm2 = gr.Text(label="Arm2")
        button_arm2 = gr.Button("Set Arm2")
    with gr.Row():        
        input_wrist = gr.Text(label="Wrist")
        button_wrist = gr.Button("Set Wrist")
    with gr.Row():
        input_claw_left = gr.Text(label="Left Claw")
        button_claw_left = gr.Button("Set Left Claw")
    with gr.Row():
        input_claw_right = gr.Text(label="Right Claw")
        button_claw_right = gr.Button("Set Right Claw")
    with gr.Row():
        button_set_default_position = gr.Button("Set Default Position")
        button_pick_object = gr.Button("Pick Object")
        button_drop_object = gr.Button("Drop Object")

    button_base.click(fn=set_base_angle, inputs=input_base)
    button_arm1.click(fn=set_arm1_angle, inputs=input_arm1)
    button_arm2.click(fn=set_arm2_angle, inputs=input_arm2)
    button_wrist.click(fn=set_wrist_angle, inputs=input_wrist)
    button_claw_left.click(fn=set_left_claw_angle, inputs=input_claw_left)
    button_claw_right.click(fn=set_right_claw_angle, inputs=input_claw_right)
    button_set_default_position.click(fn=set_default_position)
    button_pick_object.click(fn=pick_object)
    button_drop_object.click(fn=drop_object)

app.launch()