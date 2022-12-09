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

char switcher = '1';

void setup() {
  robotDoes.initializeBT();
  robotDoes.setUpSensors();
//  robotDoes.testEngines();
}

void loop() {
    
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
//  Serial.println(robotDoes.getDistanceSharp());
//  switch(switcher){
//    case 1:
//      if(robotDoes.getDistanceSharp()<=4){
//        robotDoes.setUpWheels(0,0);
//        robotDoes.turnRight();
//      }else{
//        robotDoes.setUpWheels(140,210);
//      }
//      switcher = 2;
//    case 2:
//      if(robotDoes.getDistanceSharp()<=4){
//        robotDoes.setUpWheels(0,0);
//      }else{
//        robotDoes.setUpWheels(140,210);
//      }
//  }
  if(robotDoes.getDistanceSharp()<=4){
    robotDoes.setUpWheels(0,0);
    robotDoes.turnRight();
  }else{
    robotDoes.setUpWheels(210,140);
  }
}
