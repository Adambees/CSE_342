#ifndef TOKEN_H
#define TOKEN_H

using namespace std;

enum TokenType { 
  EOL,         // end of line                   the same as the original
  VALUE,       // constant                      the same as the original
  OPAREN,      // (                             the same as the original
  CPAREN,      // )                             the same as the original

  NOT,         // ! (logical negation)          reserved for PROG 5
  BIT_COMP,    // ~                             reserved for PROG 5
  
  UN_MINUS,    // -                             reserved for PROG 5
  UN_PLUS,     // +                             reserved for PROG 5

  MULT,        // *                             the same as the original
  DIV,         // /                             the same as the original
  MODULUS,     // %                     

  PLUS,        // -                             the same as the original
  MINUS,       // +                             the same as the original

  SHIFT_L,     // <<
  SHIFT_R,     // >>
  LT,          // < 
  LE,          // <=
  GT,          // > 
  GE,          // >=

  EQUAL,       // ==
  NOTEQUAL,    // !=

  BIT_AND,     // & 
  BIT_EOR,     // ^ 
  BIT_IOR,     // | 

  LOG_AND,     // && 
  LOG_OR,      // || 
};

// the class definition is the same as the original
template <class NumericType>
class Token {
 public:
  Token( TokenType tt = EOL, const NumericType & nt = 0 )
    : theType( tt ), theValue( nt ) {
  }

  TokenType getType( ) const {
    return theType;
  }
  const NumericType &getValue( ) const {
    return theValue;
  }
  
 private:
  TokenType   theType;
  NumericType theValue;
};

#endif
