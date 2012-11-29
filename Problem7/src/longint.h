#ifndef LONGINT_H
#define LONGINT_H
#include <iostream>
#include "deque.h"

using namespace std;

class LongInt {
  friend istream &operator>>( istream &in, LongInt &rhs );
  friend ostream &operator<<( ostream &out, const LongInt &rhs );
 public:
  // Constructors
  LongInt( const string str ); 
  LongInt( const LongInt &rhs );
  LongInt( );

  // Destructor
  ~LongInt( );

  // Arithmetic binary operators
  LongInt operator+( const LongInt &rhs ) const;
  LongInt operator-( const LongInt &rhs ) const;

  // assignment operators
  const LongInt &operator=( const LongInt &rhs );

  // Logical binary operators
  bool operator< ( const LongInt & rhs ) const;
  bool operator<=( const LongInt & rhs ) const;
  bool operator> ( const LongInt & rhs ) const;
  bool operator>=( const LongInt & rhs ) const;
  bool operator==( const LongInt & rhs ) const;
  bool operator!=( const LongInt & rhs ) const;

 private:
  Deque<char> digits;
  bool negative;
  void remove0s( );
};

#endif
