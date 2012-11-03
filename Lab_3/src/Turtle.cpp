// Turtle graphics, member function definitions
#include "Turtle.h"

//------------------------------ Turtle ------------------------------------
Turtle::Turtle( float initX, float initY, float initAngle ) {
	out.open( "output.ps", ios::app );
	angle = initAngle;
	out << "%!PS-Adobe-2.0" << endl;
	out << initX << "\t" << initY << "\tmoveto" << endl;
}

//------------------------------ ~Turtle -----------------------------------
Turtle::~Turtle( ) {
	out << "stroke" << endl;
	out << "showpage" << endl;
	out.close( );
}

//-------------------------- Member functions -------------------------------
//------------------------------ draw ---------------------------------------
// draw line by distance d
void Turtle::draw( float d ) {
	float dX, dY;
	dX = d*cos(angle/180*PI);
	dY = d*sin(angle/180*PI);
	out << dX << "\t" << dY << "\trlineto" << endl;
}

//------------------------------ move ---------------------------------------
// simply move by distance d
void Turtle::move( float d ) {
	float dX, dY;
	dX = d*cos(angle/180*PI);
	dY = d*sin(angle/180*PI);
	// calculate dX
	// calculate dY
	out << dX << "\t" << dY << "\trmoveto" << endl;

}

//------------------------------ turn ---------------------------------------
// turn by angle a
void Turtle::turn( float a ) {
	angle += a;
	out << endl;
}
