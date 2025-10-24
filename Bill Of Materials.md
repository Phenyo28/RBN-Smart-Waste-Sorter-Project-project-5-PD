## 📦 Bill of Materials

| Component Name            | Purpose in Project                                                                 | Quantity |
|---------------------------|----------------------------------------------------------------------------------|----------|
| ESP32 Dev Board           | Main microcontroller used to control sensors, servos, and LEDs. Processes input signals and executes programmed actions. | 1        |
| ESP32 CAM                 | Captures images of waste items for classification using the AI model built with Edge Impulse. | 1        |
| Servo Motors              | Controls the movement of sorting flaps or lids to direct different types of waste into the correct bins. | 3        |
| Resistors                 | Protect LEDs and manage current flow in the circuit.                             | 3        |
| LEDs                      | Each LED represents a type of waste (plastic, paper, or electronic) and lights up to show where the item is being sorted. | 3        |
| Jumper Wires              | Connects all components to the breadboard and ESP32.                             | 15+      |
| Breadboard                | For building and testing the circuit.                                            | 1        |
| USB Cable                 | Provides power to the ESP32 and components during operation or testing.         | 1        |
| Ultrasonic Sensor (HC-SR04) | Detects the presence and distance of an object (waste item) to trigger the camera and sorting mechanism. | 1        |
| Buzzer                    | Provides an audio alert when an object is detected or sorting is complete.       | 1        |
