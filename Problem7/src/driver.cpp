#include <iostream>
#include "longint.h"

using namespace std;

int main( ) {
  LongInt a, b, c, d, e( "-0099999999999999999999999999999999x" );
  cout << "enter for a: ";
  cin >> a;
  cout << "enter for b: ";
  cin >> b;
  cout << "enter for c: ";
  cin >> c;
  cout << "enter for d: ";
  cin >> d;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;

  LongInt f = e;
  cout << "f = " << f << endl;

  cout << a << " + " << b << " =  " << ( a + b ) << endl;
  cout << a << " - " << b << " =  " << ( a - b ) << endl;
  cout << b << " - " << a << " =  " << ( b - a ) << endl;
  cout << b << " + " << a << " =  " << ( b + a ) << endl;
  cout << a << " == " << c << " =  " << ( a == c ) << endl;
  cout << a << " != " << c << " =  " << ( a != c ) << endl;
  cout << a << " > " << d << " =  " << ( a > d ) << endl;
  cout << a << " >= " << d << " =  " << ( a >= d ) << endl;
  cout << a << " < " << d << " =  " << ( a < d ) << endl;
  cout << a << " <= " << d << " =  " << ( a <= d ) << endl;
  cout << "f = f + 1 = " << ( f = f + *( new LongInt( "-1" ) ) ) << endl;
  cout << "e = " << e << endl;
}
