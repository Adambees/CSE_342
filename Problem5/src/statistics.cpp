#include <iostream>
#include <stdlib.h>
#include "dlist.h"
#include "mtflist.h"
#include "transposelist.h"
#include "slist.h"
#define PATTERN_MAX 10
#define SEQ_MAX 1000

using namespace std;

void initArray( int array[], int size, int randMax ) {
  for ( int i = 0; i < size; ) {
    int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if ( array[j] == tmp ) {
	hit = true;
	break;
      }
    }
    if ( hit )
      continue;
    array[i] = tmp;
    i++;
  }
}

void printArray( int array[], int size, char arrayName[] ) {
  for ( int i = 0; i < size; i++ )
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}

int main( int argc, char* argv[] ) {

  // verify argument
  if ( argc != 2 ) {
    cerr << "usage: statistics size" << endl;
    return -1;
  }
  
  // verify size
  int size = atoi( argv[1] );
  if ( size < PATTERN_MAX ) {
    cerr << "usage: size >= " << PATTERN_MAX << endl;
    return -1;
  }

  // initialize list items
  srand( 1 );
  int *items = new int[size];
  initArray( items, size, -1 );
  printArray( items, size, "items" );
    
  // initialize access pattern
  int *pattern = new int[PATTERN_MAX];
  initArray( pattern, PATTERN_MAX, size );
  printArray( pattern, PATTERN_MAX, "pattern" );
 
  // initialize pattern frequency
  int *frequency = new int[PATTERN_MAX];
  for ( int i = 1; i < PATTERN_MAX; i++ )
    frequency[i] = i + frequency[i - 1];
  printArray( frequency, PATTERN_MAX, "frequency" );

  // generate access sequence
  int *sequence = new int[SEQ_MAX];
  for ( int i = 0; i < SEQ_MAX; i++ ) {
    int random = rand( ) % ( frequency[PATTERN_MAX - 1] + 1 );
    int hit;
    for ( hit = 0; hit < PATTERN_MAX; hit++ ) {
      if ( random <= frequency[hit] ) {
	break;
      }
    }
    sequence[i] = items[pattern[hit]];
  }
  printArray( sequence, SEQ_MAX, "sequence" );

  // now conduct performance evaluation
  // doubly linked list
  DList<int> dlist;
  for ( int i = 0; i < size; i++ )
    dlist.insert( items[i], i );

  for ( int i = 0; i < SEQ_MAX; i++ )
    dlist.find( sequence[i] );

  cout << "dlist's find cost = " << dlist.getCost( ) << endl;

  // mtf list
  MtfList<int> mtflist;
  for ( int i = 0; i < size; i++ )
    mtflist.insert( items[i], i );

  for ( int i = 0; i < SEQ_MAX; i++ )
    mtflist.find( sequence[i] );

  cout << "mtflist's find cost = " << mtflist.getCost( ) << endl;

  // transpose list
  TransposeList<int> translist;
  for ( int i = 0; i < size; i++ )
    translist.insert( items[i], i );

  for ( int i = 0; i < SEQ_MAX; i++ )
    translist.find( sequence[i] );

  cout << "translist's find cost = " << translist.getCost( ) << endl;

  // skip list
  SList<int> skiplist;
  for ( int i = 0; i < size; i++ )
    skiplist.insert( items[i] );

  for ( int i = 0; i < SEQ_MAX; i++ )
    skiplist.find( sequence[i] );

  cout << "skip's find cost = " << skiplist.getCost( ) << endl;

  return 0;
}
