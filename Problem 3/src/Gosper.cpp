/*
  CSS 342 HW3
  Jay Hennen
  Gosper.cpp
  10/27/2012
  This class defines a function which creates a Gosper fractal figure.
  It can create left-handed or right-handed Gosper figures.
 */
// Gosper member function definitions
#include "Gosper.h"

//------------------------- Gosper Arrowhead ----------------------------
// Constructor; Takes initial x, y coordinates and initial angle
Gosper::Gosper( float initX, float initY, float initAngle )
: Turtle( initX, initY, initAngle ) {
}

//------------------------------ leftCurve ----------------------------------
// Draw a level-l left curve with dist d
void Gosper::leftCurve( int level, float d ) {
	if ( level > 0 ) {
		leftCurve(level-1,d);
		turn(60);
		rightCurve(level-1,d);
		turn(60);
		turn(60);
		rightCurve(level-1,d);
		turn(-60);
		leftCurve(level-1,d);
		turn(-60);
		turn(-60);
		leftCurve(level-1,d);
		leftCurve(level-1,d);
		turn(-60);
		rightCurve(level-1, d);
		turn(60);
	}
	else
		draw( d );
}

//------------------------------ rightCurve ---------------------------------
// Draw a level-l right curve with dist d
void Gosper::rightCurve( int level, float d ) {
	if ( level > 0 ) {
		turn(-60);
		leftCurve(level-1, d);
		turn(60);
		rightCurve(level-1,d);
		rightCurve(level-1,d);
		turn(60);
		turn(60);
		rightCurve(level-1,d);
		turn(60);
		leftCurve(level-1, d);
		turn(-60);
		turn(-60);
		leftCurve(level-1, d);
		turn(-60);
		rightCurve(level-1,d);
	}
	else
		draw( d );
}


