#include <iostream>
#include <string>
#include "mtflist.h"

using namespace std;

int main( ) {
  MtfList<string> facultyList;
  
  facultyList.insert( "berger", 0 );
  facultyList.insert( "cioch", 0 );
  facultyList.insert( "fukuda", 0 );
  facultyList.insert( "stiber", 0 );

  cout << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cout << facultyList.retrieve( i ) << endl;

  cout << endl;
  facultyList.remove( "cioch" );

  cout << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cout << facultyList.retrieve( i ) << endl;

  cout << endl;
  facultyList.find( "berger" );

  cout << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cout << facultyList.retrieve( i ) << endl;
}
