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

RobotFunction robotDoes;


void setup() {
  robotDoes.initializeBT();
  robotDoes.setUpSensors();
//  robotDoes.testEngines();
}

void loop() {
    
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
//  Serial.println(robotDoes.getDistanceSharp());
  static int i = 0;
  if(i<=2){
    while(robotDoes.getDistanceSharp()>5){
      robotDoes.setUpWheels(200,150);
    }
    robotDoes.setUpWheels(0,0);
    unsigned long timer = 200;
    unsigned long tempo = millis();
    while(millis()<tempo+timer){
      robotDoes.setUpWheels(200,-150);
    }
    i++;
  }else if(i=3){
    while(robotDoes.getDistanceSharp()>8){
      robotDoes.setUpWheels(200,150);
    }
    robotDoes.setUpWheels(0,0);
    unsigned long timer = 200;
    unsigned long tempo = millis();
    while(millis()<tempo+timer){
      robotDoes.setUpWheels(200,-150);
    }
    i++;
  }else if(i<=2 && robotDoes.getDistanceSharp()==4){
    robotDoes.setUpWheels(0,0);
    unsigned long timer = 200;
    unsigned long tempo = millis();
    while(millis()<tempo+timer){
      robotDoes.setUpWheels(200,-150);
    }
    i++;
  }
  else if(i<=2 && robotDoes.getDistanceSharp()==4){
    robotDoes.setUpWheels(0,0);
    unsigned long timer = 200;
    unsigned long tempo = millis();
    while(millis()<tempo+timer){
      robotDoes.setUpWheels(200,-150);
    }
    i++;
  }else if(i<=2 && robotDoes.getDistanceSharp()==4){
    robotDoes.setUpWheels(0,0);
    unsigned long timer = 200;
    unsigned long tempo = millis();
    while(millis()<tempo+timer){
      robotDoes.setUpWheels(200,-150);
    }
    i++;
  }
  
}
