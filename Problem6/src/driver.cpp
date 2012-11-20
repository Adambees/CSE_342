// A simple main to exercise Evaluator class.
#include <iostream>
#include "evaluator.h"

using namespace std;

int main( ) {
  string str;

  while ( getline( cin, str ) ) {
    Evaluator<int> e( str );
    cout << e.getValue( ) << endl;
  }
  
  return 0;
}
