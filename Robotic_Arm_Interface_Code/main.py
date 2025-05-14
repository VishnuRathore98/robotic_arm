import gradio as gr
import serial as sr

arduino = sr.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

def set_base_angle(angle):
    print("base angle: ", bytes(angle,'utf-8'))
    arduino.write(bytes(angle,'utf-8')) 

def set_arm1_angle(angle):
    print("arm1 angle: ", angle)
    arduino.write(bytes(angle, 'utf-8'))

def set_arm2_angle(angle):
    print("arm2 angle: ", angle)
    arduino.write(bytes(angle, 'utf-8'))

def set_wrist_angle(angle):
    print("wrist angle: ", angle)
    arduino.write(bytes(angle, 'utf-8'))

def set_left_claw_angle(angle):
    print("left claw angle: ", angle)
    arduino.write(bytes(angle, 'utf-8'))

def set_right_claw_angle(angle):
    print("right claw angle: ", angle)
    arduino.write(bytes(angle, 'utf-8'))

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

    button_base.click(fn=set_base_angle, inputs=input_base)
    button_arm1.click(fn=set_arm1_angle, inputs=input_arm1)
    button_arm2.click(fn=set_arm2_angle, inputs=input_arm2)
    button_wrist.click(fn=set_wrist_angle, inputs=input_wrist)
    button_claw_left.click(fn=set_left_claw_angle, inputs=input_claw_left)
    button_claw_right.click(fn=set_right_claw_angle, inputs=input_claw_right)

app.launch()