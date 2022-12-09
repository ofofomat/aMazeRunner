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
  Serial.begin(9600);
  HC.begin(9600);
  Serial.println("Initialized");
  HC.println("Initialized");
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

int RobotFunction::getDistanceSharp(){
  return sensorsIV.getDistance();
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
  while(millis()<1000){
    setUpWheels(200,200);
  }
  //Goes backward
  while(millis()<2000){
    setUpWheels(-200,-200);
  }
  //Goes right
  while(millis()<3000){
    setUpWheels(200,-200);
  }
  //Goes left
  while(millis()<4000){
    setUpWheels(-200,200);
  }
  //Stay still
  while(millis()<5000){
    setUpWheels(0,0);
  }
}

void RobotFunction::turnLeft(){
  while(getDistanceSharp()<=4){
    setUpWheels(-225,130);
  }
  HC.println("Back on running!");
}

void RobotFunction::turnRight(){
  while(getDistanceSharp()<=4){
    setUpWheels(225,-130);
  }
  HC.println("Back on running!\n");
}

void RobotFunction::callToTurn(){
  if(HC.available()>0){
    char reader = HC.read();
    switch(reader){
      case 'l':
        HC.println("You chose: Left");
        turnLeft();
        break;
      case 'r':
        HC.println("You chose: Right");
        turnRight();
        break;
      case 'L':
        HC.println("You chose: left");
        oneLeft();
        break;
      case 'R':
        HC.println("You chose: right");
        oneRight();
        break;
    }
  }
}

char RobotFunction::callToStart(){
  char reader;
  if(HC.available()>0){
    reader = HC.read();
  }
  switch(reader){
    case 's':
    return reader;
    break;
    default:
    return 'n';
    break;
  }
}

void RobotFunction::printHC(){
  int value = getDistanceSharp();
  HC.print("Value> ");
  HC.println((String)value);
}

void RobotFunction::oneLeft(){
  while(getDistanceSharp()<=4){
    setUpWheels(-180,0);
  }
  HC.println("Back on running!\n");
}

void RobotFunction::oneRight(){
  while(getDistanceSharp()<=4){
    setUpWheels(0,-130);
  }
  HC.println("Back on running!\n");
}
