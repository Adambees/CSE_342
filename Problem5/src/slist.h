#ifndef SLIST_H
#define SLIST_H

#define LEVEL 6
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Object>
struct SListNode {                  // a list node
  Object item;
  SListNode *prev;
  SListNode *next;
  SListNode *up;
  SListNode *down;
};

template <class Object>
class SList {
 public:
  SList( );                         // the constructor
  SList( const SList &rhs );        // the copy constructor
  ~SList( );                        // the destructor

  bool isEmpty( ) const;            // checks if a list is empty.
  int size( ) const;                // retrieves # list nodes;
  void clear( );                    // clean up all list entries.
  void insert( const Object &obj ); // insert a new object in a sorted order
  bool find( const Object &obj );   // return true if obj was found
  void remove( const Object &obj );      // remove a given object
  const SList &operator=( const SList &rhs );  // assignment
  int getCost( ) const;                  // return finding cost
  void show( ) const;                    // show the data structure

 protected:
  SListNode<Object> *header[LEVEL]; // header
  int cost;                         // for statistics
  void init( );                     // called from the above two constructors
  SListNode<Object> *searchPointer( const Object &obj ); // used by find
};

#include "slist.cpp.h"
#endif
