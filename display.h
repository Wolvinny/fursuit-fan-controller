#include "./checksensor.h"
#include "./formatTime.h"
#include "./button.h"
#include "./conf.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, -1);

void defaultDisplay()
{
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("Current: ");
  float temp;

  if (USE_F)
  {
    temp = sensors.getTempFByIndex(0);
  }
  else
  {
    temp = sensors.getTempCByIndex(0);
  }

  display.print(temp);
  display.setCursor(0, 10);
  display.print("Max: ");
  display.print(maxT);

  display.print(" Min: ");
  display.print(minT);

  display.setCursor(0, 20);
  display.print("Avg: ");
  float avg = averageValue.average();

  if (avg < minT)
    display.print("initializing"); // takes a while to stabilize
  else
    display.print(avg);
  display.setCursor(0, 30);
  String text = "Fan ";
  if (ledState == HIGH)
  {
    text += "ON";
  }
  else
  {
    text += "OFF";
  }
  display.println(text);

  display.setCursor(30, 50);
  // if t > 50 flash, if > 60 constant and fan on
  if (wrn && !ovht && !printed)
  {
    display.println("HI TEMP");
    printed = true;
  }
  else if (wrn && !ovht && printed)
  {
    // display.println("HI TEMP - FAN ON");
    printed = false;
  }
  else if (ovht)
  {
    display.println("HI TEMP - FAN ON");
    printed = false;
  }
  display.setCursor(0, 40);
  display.print("Last water: ");
  display.print(getFormattedMillisString(millis()));

  display.display();
}
