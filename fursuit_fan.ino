/**
*  Made by Wolvinny (treble/luna)
*  You are free to edit this code, as long as you credit me.
*  You can use this commercially (if youre a fursuit maker etc), just credit me.
*
  */


#include <Wire.h>


#include "./display.h"

void setup() {
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextSize(4);
  display.setCursor(0, 10);
  display.setTextColor(WHITE);
  display.println("Bark!");
  display.display();
  currentButtonState = digitalRead(SWITCH_PORT);
  pinMode(SWITCH_PORT, INPUT_PULLUP);
  pinMode(FAN_PORT, OUTPUT);


  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.println("Using version 1.0");
  display.setCursor(0, 10);
  display.println("https://github.com/Wolvinny/fursuit-fan-controller");
  display.setCursor(0, 40);
  display.println("Sensor initializing");
  display.setCursor(0, 50);
  display.println("Check gh for updates!");
  display.display();
  sensors.begin();

  delay(5000); //give sensor time to stabilize
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

  if (timer >= 1000) { //polling rate of sensor is 750ms 
    timer = 0;
    defaultDisplay();
    checkSensors();
  }



  delay(1);
}


