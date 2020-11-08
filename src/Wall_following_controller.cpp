#include <Romi32U4.h>
#include "Encoders.h"
#include "Wall_following_controller.h"
#include "IR_sensor.h"
#include "Sonar_sensor.h"

IRsensor SharpIR;
SonarSensor HCSR04;

int currentError = 0;
int lastError = 0;

void WallFollowingController::Init(void)
{
    SharpIR.Init();
    HCSR04.Init();
}

float WallFollowingController::Process(float target_distance)
{
  //assignment 2: write a PD controller that outputs speed as a function of distance error
  float currentDistance = SharpIR.ReadData();
  float error = target_distance - currentDistance;
  float errorDifference = error - lastError;
  float effort = effort * Kp + errorDifference * Kd;
  float speed = constrain(effort, -50.0, 50.0);
  Serial.println(speed);
  return speed;
}


    // currentTarget = target;
    // int currentPosition = getPosition();
    // float error = currentTarget - currentPosition;
    // sumOfErrors += error;
    // float errorDifference = lastError - error;
    // int effort = error * Kp + sumOfErrors * Ki + errorDifference * Kd;

    // bool isCCW;

    // if (effort > 0) {
    //     isCCW = false;
    // } else {
    //     isCCW = true;
    // }

    // setEffortWithoutDB(abs(effort), isCCW);
    // lastError = error;

    // return abs(error) < TOLERANCE;