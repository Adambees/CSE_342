/*
 ============================================================================
 Name        : Problem.cpp
 Author      : Jay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */
#include "Gosper.h"
#include <iostream>
using namespace std;

int main( )
{
  // test right hexagonal Gosper curve at level 4
  Gosper gosper1( 100, 100, 0 );
  gosper1.rightCurve( 4, 4 );

  // test left hexagonal Gosper curver at level 4
  Gosper gosper2( 500, 100, 0 );
  gosper2.leftCurve( 4, 4 );

  // test right hexagonal Gosper curve at level 3
  Gosper gosper3( 100, 400, 0 );
  gosper3.rightCurve( 3, 6 );

  // test left hexagonal Gosper curver at level 3
  Gosper gosper4( 500, 400, 0 );
  gosper4.leftCurve( 3, 6 );

  // test right hexagonal Gosper curve at level 2
  Gosper gosper5( 100, 600, 0 );
  gosper5.rightCurve( 2, 8 );

  // test left hexagonal Gosper curver at level 2
  Gosper gosper6( 500, 600, 0 );
  gosper6.leftCurve( 2, 8 );

  // test right hexagonal Gosper curve at level 1
  Gosper gosper7( 100, 700, 0 );
  gosper7.rightCurve( 1, 10 );

  // test left hexagonal Gosper curver at level 1
  Gosper gosper8( 500, 700, 0 );
  gosper8.leftCurve( 1, 10 );
}
