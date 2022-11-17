//      ////      //      ////       ////      //            ////      //      //      //      //////      //////
//      //  //    //    ////       //          //          //   //     //      ////  ////      //          //  //
//      //  //    //      ////     //          //          ///////     //      //  //  //      ////        ////
//      ////      //    ////         ////      //////      //   //     //      //      //      //////      //  //
//

/*
*********************************************************************************************************************
  This is Mateus Fernandes' (and his group) attempt to create a code for the maze robot;
  It is a open-source code, anyone can use it at will onl under the circunstances to keep this disclaimer at the code
*********************************************************************************************************************
*/



//---------------------------------------------------------------------------------------------------------------------
#include "FunctionsHere.h"
#define rxPin 10
#define txPin 11
SoftwareSerial HC(rxPin,txPin);

RobotFunctions robotDoes;


void setup() {
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  HC.begin(9600);
//  robotDoes.initializeBT();
//  robotDoes.setUpSensors();
//  robotDoes.testEngines();
}

void loop() {
  HC.println(100);
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
}
