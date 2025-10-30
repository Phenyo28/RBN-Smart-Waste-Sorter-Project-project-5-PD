# RBN-Smart-Waste-Sorter-Project-project-5-PD

## Introduction
This project is a prototype of a Smart Waste Sorter, an automated system designed to detect and sort waste materials into different bins using sensors and servo motors. It was developed using an ESP32 microcontroller, an ESP32-CAM, ultrasonic sensors, LEDs and servo motors to demonstrate how technology can make recycling more efficient and sustainable.

The system operates by sensing the distance of an approaching object using the ultrasonic sensor. When waste is detected, the corresponding bin lid automatically opens through the servo mechanism. This process reduces manual handling, improves hygiene, and promotes proper waste disposal practices.

### The Smart Waste Sorter prototype features:
- Ultrasonic distance detection to identify approaching waste.
- Servo motor–controlled lids that open automatically based on sensor input.
- Real-time automation using the ESP32 microcontroller.
- A modular design created in Onshape for easy assembly and improvement.

---
## Repository Contents

| Folder / File | Description |
|---------------|-------------|
| `code/`       | Contains all source code for the ESP32, ESP32-CAM, servo motors, ultrasonic sensor, and LED control. |
| `hardware/`   | Circuit diagrams, breadboard layouts, and component schematics. |
| `CAD/`        | Onshape design files, 3D models, and assembly drawings for the bin mechanism. |
| `images/`     | Project photos, screenshots of the prototype, and wiring setup. |
| `docs/`       | Documentation, including README, bill of materials, system overview, and test reports. |
| `AI/`         | Edge Impulse models or training datasets used for waste classification with the ESP32-CAM. |

## Perfomance Flow of the project

**1. Power On**
- System powered by Li-ion batteries or USB.
- ESP32 initializes all components and LEDs flash to indicate readiness.

**2. Object Detection**
- ESP32-CAM captures an image of the waste item placed in front of the camera.

**3. Image Classification**
AI model (Edge Impulse) identifies the waste type — plastic, paper, or electronic.

**4. LED Indication**
- Green LED: Plastic
- Yellow LED: Paper
- Red LED: Electronic

**5. Sorting Action**
ESP32 activates the corresponding servo motor to open the correct bin door.
Item drops in; servo closes after a short delay.
Feedback
OLED display shows sorting message.
Buzzer beeps to confirm successful sorting.
Reset
LEDs turn off and servos return to the closed position.
System waits for the next item.
