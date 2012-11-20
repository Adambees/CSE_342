// Public routine that performs the evaluation. Examines the postfix machine
// to see if a single result is left and if so, return it; otherwise prints
// error.
template<class NumericType>
NumericType Evaluator<NumericType>::getValue( ) {

  Tokenizer<NumericType> tok( str );
  Token<NumericType> lastToken;
  
  do {
    lastToken = tok.getToken( );
    processToken( lastToken );
  } while ( lastToken.getType( ) != EOL );

  if ( postFixStack.empty( ) ) {
    cerr << "Missing operatnd!" << endl;
    return 0;
  }

  NumericType theResult = postFixStack.back( );
  postFixStack.pop_back( );
  if ( !postFixStack.empty( ) )
    cerr << "Warning: missing operators!" << endl;
  
  return theResult;
}

// After token is read, use operator precedence parsing algorithm to process
// it; missing opening parentheses are detected here.
template<class NumericType>
void Evaluator<NumericType>::
processToken( const Token<NumericType> &lastToken ) {
  TokenType topOp;
  TokenType lastType = lastToken.getType( );

  switch( lastType ) {
  case VALUE:
    postFixStack.push_back( lastToken.getValue( ) );
    return;

  case CPAREN:
    while( ( topOp = opStack.back( ) ) != OPAREN &&
	   topOp != EOL )
      binaryOp( topOp );
    if ( topOp == OPAREN )
      opStack.pop_back( ); // get rid of opening parethesis
    else
      cerr << "Missing open parenthesis" << endl;
    break;

  default: // general operator case
    while ( PREC_TABLE[ lastType ].inputSymbol <= 
	    PREC_TABLE[ topOp = opStack.back( ) ].topOfStack )
      binaryOp( topOp );

    if ( lastToken.getType( ) != EOL )
      opStack.push_back( lastType );

    break;
  }
}

// Process an operator by taking two items off the postfix stack, applying
// the operator, and pushing the result.
// Print error if missing closing parenthesis or division by 0.
template<class NumericType>
void Evaluator<NumericType>::binaryOp( TokenType topOp ) {
  if ( topOp == OPAREN ) {
    cerr << "Unbalanced parenthss" << endl;
    opStack.pop_back( );
    return;
  }
  NumericType rhs = getTop( );
  NumericType lhs = getTop( );

  if ( topOp == BIT_EOR )
    postFixStack.push_back( NumericType( pow( lhs, rhs ) ) );
  else if ( topOp == PLUS )
    postFixStack.push_back( lhs + rhs );
  else if ( topOp == MINUS )
    postFixStack.push_back( lhs - rhs );
  else if ( topOp == MULT )
    postFixStack.push_back( lhs * rhs );
  else if ( topOp == DIV ) 
    if ( rhs != 0 )
      postFixStack.push_back( lhs / rhs );
    else {
      cerr << "Division by zero" << endl;
      postFixStack.push_back( lhs );
    }

  opStack.pop_back( );
}

// top and pop the postfix machine stack; return the result.
// If the stack is empty, print an error message.
template<class NumericType>
NumericType Evaluator<NumericType>::getTop( ) {
  if ( postFixStack.empty( ) ) {
    cerr << "Missing operand" << endl;
    return 0;
  }

  NumericType tmp = postFixStack.back( );
  postFixStack.pop_back( );
  return tmp;
}
