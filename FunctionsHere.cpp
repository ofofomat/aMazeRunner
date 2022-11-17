#include "FunctionsHere.h"

// For the QTRSensors only
QTRSensors reflector;
const uint8_t sensorAmount = 2;                        // Num of sensors
uint16_t sensors[sensorAmount];                        // Array of sensors
uint16_t arrayOfSensor[]{A0,A1};            // for Raw values reading

// For the Engines only
DCMotorController rightEngine = DCMotorController(4,6,7);  //Set pins for the engines (enable, in1, in2);
DCMotorController leftEngine  = DCMotorController(5,2,3);  //Set pins for the engines (enable, in1, in2);


// For the bluetooth only
//SoftwareSerial HC(11,10);

// For the sharp ir sensor only



//Functions per se

void RobotFunctions::initializeBT(){
//  HC.begin(9600);
}

void RobotFunctions::setUpSensors(){
  reflector.setTypeAnalog();
  reflector.setSensorPins((const uint8_t[]){A0, A1  }, sensorAmount);
  for (uint16_t i=0;i<50;i++){
    reflector.calibrate();
    delay(10);
  }
}

void RobotFunctions::setUpWheels(int leftPower, int rightPower){
  leftEngine.write(leftPower);
  rightEngine.write(rightPower);
}

void RobotFunctions::setUpSharp(){
  
}

void RobotFunctions::getRawSensors(){
  for(int i=0;i<sensorAmount;i++){
    // This sequence prints the sensor max values attatched to its sensor
    Serial.print(analogRead(arrayOfSensor[i])); 
    Serial.print(" | ");
  }
  Serial.println("\n");
  delay(1000);
}

void RobotFunctions::getCalibratedValues(){
  // receives position based on the position of sensor over the line
  uint16_t position = reflector.readLineWhite(sensors); 
  for(uint8_t i=0;i<sensorAmount;i++){
    Serial.print(sensors[i]);
    Serial.print('\t');
  }
  Serial.println(position);
  delay(250);
}

void RobotFunctions::testEngines(){
  //Goes forward
  while(millis()<2000){
    setUpWheels(200,200);
  }
  //Goes backward
  while(millis()<4000){
    setUpWheels(-200,-200);
  }
  //Goes right
  while(millis()<6000){
    setUpWheels(200,-200);
  }
  //Goes left
  while(millis()<8000){
    setUpWheels(-200,200);
  }
  //Stay still
  while(millis()<10000){
    setUpWheels(0,0);
  }
}
