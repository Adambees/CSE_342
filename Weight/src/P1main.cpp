#include <iostream>
#include "Weight.h"

using namespace std;
int main( ) {
	  Weight w1( -5, 35 ), w2( 5, -35 ), w3( 2, 5 ), w4( 1 ), w5, w6;

	  cout << "type two integers for w6: ";
	  cin >> w6;

	  cout << "w1 = " << w1 << endl;
	  cout << "w2 = " << w2 << endl;
	  cout << "w3 = " << w3 << endl;
	  cout << "w4 = " << w4 << endl;
	  cout << "w5 = " << w5 << endl;
	  cout << "w6 = " << w6 << endl;
	  cout << "-w4 = " << -w4 << endl;

	  cout << "w1 + w2 + w3 = " << w1 + w2 + w3 << endl;
	  cout << "w1 - w2 - w3 = " << w1 - w2 - w3 << endl;
	  cout << "w1 * 22 = " << w1 * 22 << endl;
	  cout << "Ratio ( w1 / w2 ) = " << w1 / w2 << endl;
	  cout << "w1 / 2.5 = " << w1 / 2.5 << endl;

	  cout << "w1 <= w2 is " << ( ( w1 <= w2 ) ? "true" : "false" ) << endl;
	  cout << "w2 >= w3 is " << ( ( w2 >= w3 ) ? "true" : "false" ) << endl;
	  cout << "w3 > w4 is " << ( ( w3 > w4 ) ? "true" : "false" ) << endl;
	  cout << "w4 < w5 is " << ( ( w4 < w5 ) ? "true" : "false" ) << endl;
	  cout << "w1 == w1 is " << ( ( w1 == w1 ) ? "true" : "false" ) << endl;
	  cout << "w1 != w1 is " << ( ( w1 != w1 ) ? "true" : "false" ) << endl;

	  cout << "(w5 += w1) += w2 is " << ( (w5 += w1) += w2 ) << endl;
	  cout << "(w5 = 0) is " << ( w5 = 0 ) << endl;
	  cout << "(w5 -= w1) -= w2 is " << ( (w5 -= w1) -= w2 ) << endl;
	  cout << "(w1 *= 11) *= 2 is " << ( (w1 *= 11) *= 2 ) << endl;
	  cout << "(w1 /= 2) / w3 is " << ( (w1 /= 2 ) / w3 ) << endl;
	  cout << " w1 / w5 = " << w1 / w5 << endl;
	  return 0;
}

