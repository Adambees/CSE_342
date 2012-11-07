#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include "quick.cpp"
#include "mergesort.cpp"
#include "mergeImproved.cpp"

//extern void initArray( vector<int> &array, int rand_max );
//extern void printArray( vector<int> &array, char name[] );

void initArray( vector<int> &array, int randMax ) {
  int size = array.size( );

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

// array printing
void printArray( vector<int> &array, char arrayName[] ) {
  int size = array.size( );

  for ( int i = 0; i < size; i++ )
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}

// performance evaluation
int elapsed( timeval &startTime, timeval &endTime ) {
  return ( endTime.tv_sec - startTime.tv_sec ) * 1000000
    + ( endTime.tv_usec - startTime.tv_usec );
}

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
  cout << "data initialization" << endl;
  srand( 1 );
  vector<int> items1( size );
  initArray( items1, size );
  // cout << "initial " << endl;
  // printArray( items1, "items1" );

  vector<int> items2 = items1;
  vector<int> items3 = items1;

  cout << "start performance evaluation" << endl;
  // timeval preparation
  struct timeval startTime, endTime;

  // quicksort
  gettimeofday( &startTime, 0 );
  quicksort( items1 );
  gettimeofday( &endTime, 0 );
  cout << "quicksort: " << elapsed( startTime, endTime ) << endl;
  // printArray( items1, "items1" );

  // mergesort
  gettimeofday( &startTime, 0 );
  mergesort( items2 );
  gettimeofday( &endTime, 0 );
  cout << "mergesort: " << elapsed( startTime, endTime ) << endl;
  // printArray( items2, "items2" );

  // mergesort improved
  gettimeofday( &startTime, 0 );
  mergeImproved( items3 );
  gettimeofday( &endTime, 0 );
  cout << "mergesort improved: " << elapsed( startTime, endTime ) << endl;
  //printArray( items3, "items3" );


  return 0;
}
