#include <Romi32U4.h>
#include "Sonar_sensor.h"

float sonarStartTime = 0;
float sonarEndTime = 0;
float sonarEchoPin = 1;

void EchoISR(void);

void SonarSensor::Init(void)
{
    pinMode(pin_TRIG,OUTPUT);
    pinMode(pin_ECHO, INPUT);   
    attachInterrupt(digitalPinToInterrupt(pin_ECHO), EchoISR, CHANGE);
}

float SonarSensor::PrintData(void)
{
    Serial.println(ReadData());
}

float SonarSensor::ReadData(void)
{
    //assignment 1.2
    //read out and calibrate your sonar sensor, to convert readouts to distance in [cm]
    noInterrupts();
    unsigned long duration = sonarEndTime - sonarStartTime;
    float distance = duration * 0.034 / 2; // [cm]

    Serial.println();
    Serial.print(duration);
    Serial.print(",");
    Serial.print(distance);
    interrupts();
    return duration;
}

float SonarSensor::Ping(void) {
    digitalWrite(pin_TRIG, HIGH);
    delayMicroseconds(100);
    digitalWrite(pin_TRIG, LOW);
    delay(100);
}

void EchoISR(void) {
    if (digitalRead(sonarEchoPin)) {sonarStartTime = micros();}
    else {sonarEndTime = micros();}
}