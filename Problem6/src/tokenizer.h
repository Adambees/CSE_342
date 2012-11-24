#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>

#include "token.h"
using namespace std;

template <class NumericType>
class Tokenizer {
 public:
  Tokenizer( istream &is ) : in( is ), prevToken( OPAREN ) {
  }
  Token<NumericType> getToken( );

 private:
  istream &in;
  bool getChar( char &ch );

  TokenType prevToken; // it may be necessary for the programming assignment 6
};

#include "tokenizer.cpp.h"
#endif
