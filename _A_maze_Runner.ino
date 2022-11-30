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
#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 9
SoftwareSerial HC(rxPin,txPin);

//---------------------------------------------------------------------------------------------------------------------
#include "FunctionsHere.h"

RobotFunction robotDoes;


void setup() {
//  robotDoes.initializeBT();
//  robotDoes.setUpSensors();
//  robotDoes.testEngines();
HC.begin(9600);
Serial.begin(9600);
HC.println("Initializing...");
Serial.println("Initializing...");
}

void loop() {
    
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
//  robotDoes.getDistanceSharp();
  if(HC.available()>0){
    String texto1 = HC.readString();
    HC.println("Manfred> "+texto1);
    Serial.println("Manfred> "+texto1);
  }
  if(Serial.available() > 0){
    String texto2 = Serial.readString();
    Serial.println("Mateus> "+texto2);
    HC.println("Mateus> "+texto2);
  }
}
