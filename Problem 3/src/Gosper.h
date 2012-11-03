/*
  CSS 342 HW3
  Jay Hennen
  Gosper.h
  10/27/2012
  This class defines a function which creates a Gosper fractal figure.
  It can create left-handed or right-handed Gosper figures.
 */
#ifndef GOSPER_H
#define GOSPER_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Gosper : Turtle {
public:
  Gosper( float initX=0.0, float initY=0.0, float initAngle=0.0 );
  void leftCurve( int l, float d );  //draw a level-l left curve with dist d
  void rightCurve( int l, float d ); //draw a level-l right curve with dist d
};
#endif
