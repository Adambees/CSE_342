#include "Turtle.h"
#include <iostream>
using namespace std;
int main( )
{
  Turtle turtle(50, 50);

  turtle.turn(45);
  turtle.draw(200);
  turtle.turn(-135);
  turtle.move(140);
  turtle.turn(225);
  turtle.draw(200);
}
