#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <math.h>        // for pow( )
#include <sstream>       // for stringstream
#include <vector>        // for vector
#include "tokenizer.h"

using namespace std;

// PREC_TABLE matches order of TokenType enumeration.
struct Precedence {
  int inputSymbol;
  int topOfStack;
};

template <class NumericType>
class Evaluator {
 public:
  Evaluator( const string &s ) : str( s ) { // constructor receives an exp
    opStack.push_back( EOL );

    PREC_TABLE[0].inputSymbol = 0;      // EOL
    PREC_TABLE[0].topOfStack =  -1;
    PREC_TABLE[1].inputSymbol = 0;      // VALUE
    PREC_TABLE[1].topOfStack =  0;
    PREC_TABLE[2].inputSymbol = 100;    // OPAREN 
    PREC_TABLE[2].topOfStack =  0;
    PREC_TABLE[3].inputSymbol = 99;     // CPAREN
    PREC_TABLE[3].topOfStack =  0;

    PREC_TABLE[4].inputSymbol = 21;     // NOT
    PREC_TABLE[4].topOfStack = 22;      // 
    PREC_TABLE[5].inputSymbol = 21;     // BIT_COMP
    PREC_TABLE[5].topOfStack = 22;      //
    PREC_TABLE[6].inputSymbol = 21;     // UN_MINUS  reserved for PROG 6
    PREC_TABLE[6].topOfStack = 22;      //
    PREC_TABLE[7].inputSymbol = 21;     // UN_PLUS   reserved for PROG 6
    PREC_TABLE[7].topOfStack = 22;      //

    PREC_TABLE[8].inputSymbol = 19;     // MULT
    PREC_TABLE[8].topOfStack =  20;
    PREC_TABLE[9].inputSymbol = 19;     // DIV
    PREC_TABLE[9].topOfStack =  20;
    PREC_TABLE[10].inputSymbol = 19;    // MOD
    PREC_TABLE[10].topOfStack =  20;

    PREC_TABLE[11].inputSymbol = 17;    // PLUS
    PREC_TABLE[11].topOfStack =  18;
    PREC_TABLE[12].inputSymbol = 17;    // MINUS
    PREC_TABLE[12].topOfStack =  18;

    PREC_TABLE[13].inputSymbol = 15;    // SHIFT_L 
    PREC_TABLE[13].topOfStack =  16;
    PREC_TABLE[14].inputSymbol = 15;    // SHIFT_R
    PREC_TABLE[14].topOfStack =  16;

    PREC_TABLE[15].inputSymbol = 13;    // LT
    PREC_TABLE[15].topOfStack =  14;
    PREC_TABLE[16].inputSymbol = 13;    // LE
    PREC_TABLE[16].topOfStack =  14;
    PREC_TABLE[17].inputSymbol = 13;    // GT
    PREC_TABLE[17].topOfStack =  14;
    PREC_TABLE[18].inputSymbol = 13;    // GE
    PREC_TABLE[18].topOfStack =  14;

    PREC_TABLE[19].inputSymbol = 11;    // EQUAL
    PREC_TABLE[19].topOfStack =  12;
    PREC_TABLE[20].inputSymbol = 11;    // NOTEQUAL
    PREC_TABLE[20].topOfStack =  12;

    PREC_TABLE[21].inputSymbol = 9;    // BIT_AND
    PREC_TABLE[21].topOfStack =  10;

    PREC_TABLE[22].inputSymbol = 7;    // BIT_EOR
    PREC_TABLE[22].topOfStack =  8; 

    PREC_TABLE[23].inputSymbol = 5;    // BIT_IOR
    PREC_TABLE[23].topOfStack =  6; 

    PREC_TABLE[24].inputSymbol = 3;    // LOG_AND
    PREC_TABLE[24].topOfStack =  4; 

    PREC_TABLE[25].inputSymbol = 1;    // LOG_OR
    PREC_TABLE[25].topOfStack =  2; 
  }
    
  NumericType getValue( );                  // Do the evaluation

 private:
  Precedence PREC_TABLE[26];                // precedence table
  vector<TokenType> opStack;                // Operator stack for conversion
  vector<NumericType> postFixStack;         // Postfix machine stack
  istringstream str;                        // The character stream

  // Internal routines
  NumericType getTop( );                    // Get top of postfix stack
  void binaryOp( TokenType topOp );         // Process an operator
  void processToken( const Token<NumericType> &lastToken );
};

#include "evaluator.cpp.h"
#endif
