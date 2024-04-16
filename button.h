#pragma once

const int BUTTON_PIN = 6; // Arduino pin connected to button's pin
const int LED_PIN    = 5;
int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
