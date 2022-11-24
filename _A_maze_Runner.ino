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

RobotFunctions robotDoes;


void setup() {
  robotDoes.initializeBT();
//  robotDoes.setUpSensors();
//  robotDoes.testEngines();
}

void loop() {  
//  robotDoes.getRawSensors();
//  robotDoes.getCalibratedValues();
  robotDoes.getDistanceSharp();
}
