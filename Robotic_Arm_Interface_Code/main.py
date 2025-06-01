import time
import gradio as gr
import serial as sr
from functools import partial
import right_arm_actions as ra
import left_arm_actions as la

try:
    arduino = sr.Serial(port="/dev/ttyUSB0", baudrate=9600, timeout=0.1)
    time.sleep(2)
    print("Connected to USB0 port")
except Exception as e:
    print("port ttyUSB0 not available")
    try:
        arduino = sr.Serial(port="/dev/ttyACM0", baudrate=9600, timeout=0.1)
        time.sleep(2)
        print("Connected to ACM0 port")
    except:
        print("port ttyACM0 not available")
        try:
            arduino = sr.Serial(port="/dev/ttyACM1", baudrate=9600, timeout=0.1)
            time.sleep(2)
            print("Connected to ACM1 port")
        except:
            print("port ttyACM1 not available")
            try:
                arduino = sr.Serial(port="/dev/ttyACM2", baudrate=9600, timeout=0.1)
                time.sleep(2)
                print("Connected to ACM2 port")
            except:
                print("port ttyACM2 not available")


def fold_object(arduino):
    la.left_arm_fold1_object()
    ra.right_arm_fold2_object()


with gr.Blocks() as app:

    with gr.Tab(label="Manual Control"):

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

                    left_arm_input_fold = gr.Text(label="Fold")
                    left_arm_button_fold = gr.Button("Set Fold Angle")

                left_arm_button_base.click(
                    fn=partial(la.set_left_arm_base_angle, arduino=arduino),
                    inputs=[left_arm_input_base],
                )
                left_arm_button_arm1.click(
                    fn=partial(la.set_left_arm_arm1_angle, arduino=arduino),
                    inputs=[left_arm_input_arm1],
                )
                left_arm_button_arm2.click(
                    fn=partial(la.set_left_arm_arm2_angle, arduino=arduino),
                    inputs=[left_arm_input_arm2],
                )
                left_arm_button_wrist.click(
                    fn=partial(la.set_left_arm_wrist_angle, arduino=arduino),
                    inputs=[left_arm_input_wrist],
                )
                left_arm_button_claw.click(
                    fn=partial(la.set_left_arm_claw_angle, arduino=arduino),
                    inputs=[left_arm_input_claw],
                )
                left_arm_button_fold.click(
                    fn=partial(la.set_left_arm_fold_angle, arduino=arduino),
                    inputs=[left_arm_input_fold],
                )

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

                    right_arm_input_hold = gr.Text(label="Hold")
                    right_arm_button_hold = gr.Button("Set Hold angle")

                right_arm_button_base.click(
                    fn=partial(ra.set_right_arm_base_angle, arduino=arduino),
                    inputs=[right_arm_input_base],
                )
                right_arm_button_arm1.click(
                    fn=partial(ra.set_right_arm_arm1_angle, arduino=arduino),
                    inputs=[right_arm_input_arm1],
                )
                right_arm_button_arm2.click(
                    fn=partial(ra.set_right_arm_arm2_angle, arduino=arduino),
                    inputs=[right_arm_input_arm2],
                )
                right_arm_button_wrist.click(
                    fn=partial(ra.set_right_arm_wrist_angle, arduino=arduino),
                    inputs=[right_arm_input_wrist],
                )
                right_arm_button_claw.click(
                    fn=partial(ra.set_right_arm_claw_angle, arduino=arduino),
                    inputs=[right_arm_input_claw],
                )
                right_arm_button_hold.click(
                    fn=partial(ra.set_right_arm_hold_angle, arduino=arduino),
                    inputs=[right_arm_input_hold],
                )

    with gr.Tab(label="Automatic Control"):
        with gr.Row():

            with gr.Column():
                gr.Markdown("# **Left Arm**")

                left_arm_button_set_default_position = gr.Button("Set Default Position")
                left_arm_button_fold1_object = gr.Button("Fold 1")
                left_arm_button_fold3_object = gr.Button("Fold 3")
                left_arm_button_unfold_arm = gr.Button("Unfold Left Arm")
                left_arm_button_fold4_object = gr.Button("Fold 4")

                left_arm_button_set_default_position.click(
                    fn=partial(la.set_left_arm_default_position, arduino=arduino)
                )
                left_arm_button_fold3_object.click(
                    fn=partial(la.left_arm_fold3_object, arduino=arduino)
                )
                left_arm_button_fold1_object.click(
                    fn=partial(la.left_arm_fold1_object, arduino=arduino)
                )
                left_arm_button_fold4_object.click(
                    fn=partial(la.left_arm_fold4_object, arduino=arduino)
                )
                left_arm_button_unfold_arm.click(
                    fn=partial(la.left_arm_unfold_arm, arduino=arduino)
                )

            with gr.Column():
                gr.Markdown("# **Right Arm**")

                right_arm_button_set_default_position = gr.Button(
                    "Set Default Position"
                )
                right_arm_button_fold2_object = gr.Button("Fold 2")
                right_arm_button_unfold_object = gr.Button("Unfold Right Arm")
                right_arm_button_hold_object = gr.Button("Hold Object")
                right_arm_button_pick_object = gr.Button("Pick Object")

                right_arm_button_set_default_position.click(
                    fn=partial(ra.set_right_arm_default_position, arduino=arduino)
                )
                right_arm_button_unfold_object.click(
                    fn=partial(ra.right_arm_unfold_object, arduino=arduino)
                )
                right_arm_button_fold2_object.click(
                    fn=partial(ra.right_arm_fold2_object, arduino=arduino)
                )
                right_arm_button_pick_object.click(
                    fn=partial(ra.right_arm_pick_object, arduino=arduino)
                )
                right_arm_button_hold_object.click(
                    fn=partial(ra.right_arm_hold_object, arduino=arduino)
                )
app.launch()
