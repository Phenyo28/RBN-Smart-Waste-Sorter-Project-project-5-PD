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
- The ESP32-CAM and ESP32 controller initialize.
- All LEDs and servo motors are set to their default (off/closed) state.

**2. Image Capture**
- When an item is placed near the bin’s opening, the ESP32-CAM captures an image of the waste.

**3. Waste Detection**
- The captured image is processed by the trained Edge Impulse AI model.
- The model identifies the type of waste (e.g. plastic, paper, or metal).

**4. Signal Transmission**
- The ESP32-CAM sends a signal to the main ESP32 board indicating which waste type was detected.

**5. LED Indication**
- The corresponding LED (red, blue, or yellow) turns on to show which bin category is being accessed.

**6. Servo Door Activation**
- The servo motor linked to that specific category’s door rotates to open the bin.
- A short delay allows the user to drop the waste in.

**7. Door Closure**
- After the delay, the servo motor returns to its original position, closing the bin door automatically.

**8. System Reset**
- The LED turns off and the system resets, ready for the next item.

**9. Continuous Operation**
- The process repeats for every new waste item detected by the ESP32-CAM.
