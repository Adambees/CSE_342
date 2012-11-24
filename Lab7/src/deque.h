#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>

using namespace std;

template <class Object>
class Deque {
 public:
  Deque( );                                   // the constructor
  Deque( const Deque &rhs );                  // the copy constructor
  ~Deque( );                                  // the destructor

  bool isEmpty( ) const;                      // checks if a deque is empty.
  int size( ) const;                          // retrieves # deque nodes
  const Object &getFront( ) const;            // retrieve the front node
  const Object &getBack( ) const;             // retrieve the tail node

  void clear( );                              // clean up all deque entries.
  void addFront( const Object &obj );         // add a new node to the front
  void addBack( const Object &obj );          // add a new node to the tail
  Object removeFront( );                      // remove the front node
  Object removeBack( );                       // remove the tail node

  const Deque &operator=( const Deque &rhs ); // assignment

 private:
  struct DequeNode {                          // a deque node
    Object item;
    DequeNode *next;
    DequeNode *prev;
  };
  DequeNode *front;
  DequeNode *back;
};

#include "deque.cpp.h"
#endif
