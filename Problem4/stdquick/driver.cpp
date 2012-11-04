#include <iostream>
#include <vector>
#include "quicksort.cpp"

extern void initArray( vector<int> &array, int rand_max );
extern void printArray( vector<int> &array, char name[] );

int main( int argc, char* argv[] ) {
  // verify arguments
  if ( argc != 2 ) {
    cerr << "usage: quicksort size" << endl;
    return -1;
  }

  // verify an array size
  int size = atoi( argv[1] );
  if ( size <= 0 ) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // array generation
  srand( 1 );
  vector<int> items( size );
  initArray( items, size );
  cout << "initial:" << endl;
  printArray( items, "items" );

  // quicksort
  quicksort( items );
  cout << "sorted:" << endl;
  printArray( items, "items" );

  return 0;
}
