#pragma once

#include <SoftwareSerial.h>
#include "QTRSensors.h"
#include "MotorController.h"
#include "SharpIR.h"

class RobotFunction{
  //attributes
  public:

  //methods
  public:
  //Starts HC05
  void initializeBT();
  //Starts QTRSensors
  void setUpSensors();
  //Starts DC Motors
  void setUpWheels(int leftPower, int rightPower);
  //Starts the visor
  void getDistanceSharp();
  //Read raw sensor values
  void getRawSensors();
  //Read calibrated sensor values
  void getCalibratedValues();
  //Tests motors
  void testEngines();
  //

};
