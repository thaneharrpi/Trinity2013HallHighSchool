#include "./robot.h"

//Returns distance from ir sensor in  cm. Regression equations obtained through testing.
double getDistance(int ir) {
  double distance;
  switch(ir){
    //case 0: distance=1/(0.0000643062*analogRead(ir)+0.00290751)-5.48522; break;
    case 0: distance=1/(0.000229437*analogRead(ir)-.00941669)+.380634; break;
            //case 1: distance=1/(0.000184102*analogRead(ir)-0.00284968)-0.706812; break;
    case 2: distance=1/(0.000164445*analogRead(ir)-0.000429774)-2.25411; break;
    case 3: distance=1/(0.000139331*analogRead(ir)+0.00487296)-4.58425; break;
    default: distance=1/(0.0000998145*analogRead(ir)+0.006314430) - 9.30495; break; //usually good enough
  }
  if(distance>0){
    return distance;
  }
  else{
    return 80;
  }
}
