#include "./button.h"
#include "./conf.h"

#include <OneWire.h>
#include <DallasTemperature.h>
#include <AverageValue.h>


int wrn = false;
int ovht = false;
int printed = false;
int trig = false;

float maxT = 0;
float minT = 50;

OneWire oneWire(TEMP_PORT);
DallasTemperature sensors(&oneWire);

const long MAX_VALUES_NUM = 40;
// 40 measurements
AverageValue<float> averageValue(MAX_VALUES_NUM);

void checkSensors()
{
  sensors.requestTemperatures();

  float curr;

  if (USE_F)
  {
    curr = sensors.getTempFByIndex(0);
  }
  else
  {
    curr = sensors.getTempCByIndex(0);
  }

  averageValue.push(curr);

  if (curr > maxT)
  {
    maxT = curr;
  }

  if (curr < minT)
  {
    minT = curr;
  }

  if (curr > TEMP_WARN)
  {
    if (curr > TEMP_OVHT)
    {

      if (!trig)
      {
        ledState = HIGH;
        digitalWrite(LED_PIN, HIGH);
        trig = true; // avoid this turning the fan on again if you manually turn it off
      }
      ovht = true;
    }
    else
    {
      wrn = true;
    }
  }

  if (ovht && curr < TEMP_WARN)
  {
    wrn = false;
    if (ovht)
    {
      ledState = LOW;
      digitalWrite(LED_PIN, LOW);
      ovht = false;
      trig = false;
    }
  }
  else if (wrn && curr < TEMP_WARN)
  {
    wrn = false;
  }
}
