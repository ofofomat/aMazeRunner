#include "FunctionsHere.h"

// For the QTRSensors only
QTRSensors reflector;
const uint8_t sensorAmount = 2;                        // Num of sensors
uint16_t sensors[sensorAmount];                        // Array of sensors
uint16_t arrayOfSensor[]{A0,A1};            // for Raw values reading

// For the Engines only
DCMotorController rightEngine = DCMotorController(4,6,7);  //Set pins for the engines (enable, in1, in2);
DCMotorController leftEngine  = DCMotorController(5,2,3);  //Set pins for the engines (enable, in1, in2);

// For the Bluetooth only
#define rxPin 10
#define txPin 9
SoftwareSerial HC(rxPin,txPin);

// For the sharp ir sensor only
SharpIR sensorsIV(SharpIR::GP2Y0A41SK0F, A2);


//Functions per se

void RobotFunction::initializeBT(){
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  HC.begin(38400);
}

void RobotFunction::setUpSensors(){
  reflector.setTypeAnalog();
  reflector.setSensorPins((const uint8_t[]){A0, A1}, sensorAmount);
  for (uint16_t i=0;i<50;i++){
    reflector.calibrate();
    delay(10);
  }
}

void RobotFunction::setUpWheels(int leftPower, int rightPower){
  leftEngine.write(leftPower);
  rightEngine.write(rightPower);
}

void RobotFunction::getDistanceSharp(){
  Serial.println(sensorsIV.getDistance());
}

void RobotFunction::getRawSensors(){
  for(int i=0;i<sensorAmount;i++){
    // This sequence prints the sensor max values attatched to its sensor
    Serial.print(analogRead(arrayOfSensor[i])); 
    Serial.print(" | ");
  }
  Serial.println("\n");
  delay(1000);
}

void RobotFunction::getCalibratedValues(){
  // receives position based on the position of sensor over the line
  uint16_t position = reflector.readLineBlack(sensors); 
  for(uint8_t i=0;i<sensorAmount;i++){
    Serial.print(sensors[i]);
    Serial.print('\t');
  }
  Serial.println(position);
  delay(250);
}

void RobotFunction::testEngines(){
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
