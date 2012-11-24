#include <iostream>
#include "deque.h"

using namespace std;

int main( ) {
  Deque<int> deque1;
  int item;

  for ( int j = 0; j < 5; j++ )
    deque1.addBack( j );
  for ( int j = 5; j < 10; j++ )
    deque1.addFront( j );

  Deque<int> deque2 = deque1;
  deque2.addBack( 10 );

  cout << "deque1: " << endl;
  while ( !deque1.isEmpty( ) )
    cout << deque1.removeFront( ) << endl;

  cout << "deque2: " << endl;
  while ( !deque2.isEmpty( ) )
    cout << deque2.removeBack( ) << endl;
}
