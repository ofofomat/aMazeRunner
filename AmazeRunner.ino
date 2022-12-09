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
//    robotDoes.printHC();
  if(robotDoes.callToStart()=='s'){
    if(robotDoes.getDistanceSharp()>=6){
      robotDoes.setUpWheels(235,130);
    }else{
      if(robotDoes.getDistanceSharp()<=4){
        robotDoes.setUpWheels(0,0);
        robotDoes.callToTurn();
      }
    }
  }
}
