// Sierpinski Class
#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Sierpinski : Turtle {
public:
  Sierpinski( float initX=0.0, float initY=0.0, float initAngle=0.0 );
  void leftCurve( int l, float d );  //draw a level-l left curve with dist d
  void rightCurve( int l, float d ); //draw a level-l right curve with dist d
};
#endif
