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

int testing = 0;

RobotFunctions robotDoes;


void setup() {
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  HC.begin(38400);
//  robotDoes.initializeBT();
//  robotDoes.setUpSensors();
//  robotDoes.testEngines();
}

void loop() {
  if(HC.available() > 0){
    testing = HC.read();
  }
  if(testing=='0'){
    robotDoes.testEngines();
    HC.println("Testa motores");
    testing = 0;
  }
  else if(testing=='1'){
    robotDoes.getRawSensors();
    HC.println("Retorna valores");
    testing = 0;
  }
  
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
}
