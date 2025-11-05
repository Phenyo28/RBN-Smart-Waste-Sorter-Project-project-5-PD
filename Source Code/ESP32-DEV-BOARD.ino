#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Servo and LED Setup
Servo servoRed;
Servo servoBlue;
Servo servoYellow;

// Servo pins
int servoRedPin = 12;
int servoBluePin = 14;
int servoYellowPin = 13;

// LED pins
int ledRed = 25;
int ledBlue = 26;
int ledYellow = 27;

// OLED Display Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ESP-NOW Structure
typedef struct struct_message {
  char Waste[32];
} struct_message;

struct_message myData;

// Function to Open/Close a Bin
void openBin(String type) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  if (type == "paper") {
    Serial.println("Opening BLUE bin for PAPER...");
    display.println("Opening BLUE bin...");
    display.display();

    digitalWrite(ledBlue, HIGH);
    servoBlue.write(125);
    delay(3000);
    servoBlue.write(0);
    delay(1000);
    digitalWrite(ledBlue, LOW);
  }

  else if (type == "plastic") {
    Serial.println("Opening YELLOW bin for PLASTIC...");
    display.println("Opening YELLOW bin...");
    display.display();

    digitalWrite(ledYellow, HIGH);
    servoYellow.write(125);
    delay(3000);
    servoYellow.write(0);
    delay(1000);
    digitalWrite(ledYellow, LOW);
  }

  else if (type == "electronic waste" || type == "e-waste" || type == "electronics") {
    Serial.println("Opening RED bin for ELECTRONIC WASTE...");
    display.println("Opening RED bin...");
    display.display();

    digitalWrite(ledRed, HIGH);
    servoRed.write(125);
    delay(3000);
    servoRed.write(0);
    delay(1000);
    digitalWrite(ledRed, LOW);
  }

  else {
    Serial.print("Unknown waste type: ");
    Serial.println(type);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Unknown waste type");
    display.display();
    delay(2000);
  }

  // After each action, return to waiting screen
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Waiting for detection...");
  display.display();
  Serial.println("Waiting for detection...");
}

// Callback when data is received 
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len)
 {
  memcpy(&myData, incomingData, sizeof(myData));
  String wasteType = String(myData.Waste);
  wasteType.trim(); // remove spaces/newlines
  wasteType.toLowerCase();

  Serial.print("\nReceived waste type: ");
  Serial.println(wasteType);

  openBin(wasteType);
}

// Setup
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Initialize Servos 
  servoRed.attach(servoRedPin);
  servoBlue.attach(servoBluePin);
  servoYellow.attach(servoYellowPin);

  // Initialize LEDs 
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledYellow, LOW);

  // Initialize OLED
  if (!display  .begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Smart Bin Starting...");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Waiting for detection...");
  display.display();

  Serial.println("Smart Bin Receiver Ready. Waiting for detection...");

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
}

// Loop
void loop() {
  // Nothing here; everything handled by ESP-NOW callback
}
