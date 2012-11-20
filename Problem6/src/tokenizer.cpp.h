template <class NumericType>
bool Tokenizer<NumericType>::getChar( char &ch ) {
  char tmp;

  // skip blanks
  while ( in.get( tmp ) && tmp == ' ' );

  // read a char 
  if ( in.good( ) && tmp != '\n'&& tmp != '\0' ) {
    ch = tmp;
    return true; // if it is not a delimiter
  }
  else
    return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken( ) {

  char ch;
  NumericType theValue;

  if ( getChar( ch ) == true ) {
    switch( ch ) {
    case '^': return BIT_EOR;
    case '/': return DIV;
    case '*': return MULT;
    case '(': return OPAREN;
    case ')': return CPAREN;
    case '+': return PLUS;
    case '%': return MODULUS;
    case '<':
    	if (getChar(ch)) {
    		switch (ch) {
    		case '<': return SHIFT_L; // (prevToken = SHIFT_L)
    		case '=': return LE;
    		}
    	}
    	in.putback(ch);
    	return LT;
    case '>':
    	if (getChar(ch)) {
    		switch (ch) {
    		case '>': return SHIFT_R; // (prevToken = SHIFT_L)
    		case '=': return GE;
    		}
    	}
    	in.putback(ch);
    	return GT;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    case '-': return MINUS;
    default:
      in.putback( ch );
      if ( !( in >> theValue ) ) {
	cerr << "Parse error" << endl;
	return EOL;
      }
      return Token<NumericType>( VALUE, theValue );
    }
  }

  return EOL;
}
