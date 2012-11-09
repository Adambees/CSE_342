#ifndef DLIST_H
#define DLIST_H
#include <iostream>

using namespace std;

template <class Object>
struct DListNode {                  // a list node
  Object item;
  DListNode *prev;
  DListNode *next;
};

template <class Object>
class DList {
 public:
  DList( );                         // the constructor
  DList( const DList &rhs );        // the copy constructor
  ~DList( );                        // the destructor

  bool isEmpty( ) const;            // checks if a list is empty.
  int size( ) const;                // retrieves # list nodes;
  void clear( );                    // clean up all list entries.
  void insert( const Object &obj, const int index );// insert a new object
                                                    // after this index
  int find( const Object &obj );                    // find the object position
  void remove( const Object &obj );                 // remove a given object
  const DList &operator=( const DList &rhs );       // assignment
  Object retrieve( const int index ) const;         // get an indexed object
  int getCost( ) const;                             // return finding cost

 protected:
  DListNode<Object> *header;                        // header
  int cost;                                         // for statistics
  DListNode<Object> *findByIndex( const int index ) const; // an indexed object
};

#include "dlist.cpp.h"
#endif
