#pragma once

const int DISPLAY_WIDTH = 128; //the width of your oled display. If you have a larger / smaller one, text might not render correctly
const int DISPLAY_HEIGHT = 64;

const int TEMP_WARN = 50;
const int TEMP_OVHT = 60;

const int USE_F = false; //Whether to use °F instead of °C.



//Arduino ports. Only use digital ports (D2 - D12)
const int FAN_PORT = 5; //The port going to your transistor.
const int SWITCH_PORT = 6; // the port your reed switch is plugged into
const int TEMP_PORT = 8; // The port your temperature sensor is plugged into.
//i2c ports (A4 & A5) cannot be changed.