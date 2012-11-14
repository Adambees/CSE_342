#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

int main( ) {
  SList<int> *intList = new SList<int>;

  delete intList;

  SList<string> facultyList;

  facultyList.insert( "unknown" );
  facultyList.insert( "erdly" );
  facultyList.insert( "sung" );
  facultyList.insert( "olson" );
  facultyList.insert( "zander" );
  facultyList.insert( "berger" );
  facultyList.insert( "cioch" );
  facultyList.insert( "fukuda" );
  facultyList.insert( "stiber" );
  facultyList.insert( "jackels" );

  cout << "#faculty members: " << facultyList.size( ) << endl;  
  facultyList.show( );
  cout << endl;

  cout << "deleting unknown" << endl;
  facultyList.remove( "unknown" );
  cout << "#faculty members: " << facultyList.size( ) << endl;
  facultyList.show( );
  cout << endl;

  cout << "finding stiber = " << facultyList.find( "stiber" ) << endl;
  cout << endl;

  cout << "create another list" << endl;
  SList<string> studentList = facultyList;
  cout << "finding stiber = " << facultyList.find( "stiber" ) << endl;
  cout << "#faculty members: " << facultyList.size( ) << endl;
  cout << endl;

  cout << "cost of find = " << facultyList.getCost( ) << endl;
}
