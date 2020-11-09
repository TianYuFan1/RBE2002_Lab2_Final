#include <Romi32U4.h>
#include "IR_sensor.h"

void IRsensor::Init(void)
{
    pinMode(pin_IR, INPUT);
}

float IRsensor::PrintData(void)
{
    Serial.println(ReadData());
}

float IRsensor::ReadData(void)
{
  //assignment 1.1
  //read out and calibrate your IR sensor, to convert readouts to distance in [cm]
  int adc = analogRead(pin_IR);
  float voltage = (5.0/1024.0) * adc;
  return voltage;
  // float inverse_distance = 0.0408*voltage + 0.0004;
  // float distance = 1.0/inverse_distance;
  // return distance;
}