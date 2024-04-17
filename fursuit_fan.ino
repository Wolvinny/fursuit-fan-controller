#include <Wire.h>


#include "./display.h"

#define OLED_RESET 4

void setup() {



  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(0, 10);
  display.setTextColor(WHITE);
  display.println("Bark!");
  display.display();

  currentButtonState = digitalRead(BUTTON_PIN);

  sensors.begin();

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  delay(3000); //give sensor time to stabilize, print initialization screen

  checkSensors();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  defaultDisplay();

}

int timer = 0;

void loop() {

  lastButtonState = currentButtonState;  
  currentButtonState = digitalRead(BUTTON_PIN); 

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    // toggle state of LED
    ledState = !ledState;
   
    digitalWrite(LED_PIN, ledState);
    defaultDisplay();
    delay(250); //debounce
  }

  timer++;

  if (timer >= 1000) {
    timer = 0;
    defaultDisplay();
    checkSensors();
  }



  delay(1);
}


