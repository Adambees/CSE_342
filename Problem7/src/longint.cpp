/*
 ============================================================================
 Name        : Problem7.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

using namespace std;

// Constructors
LongInt::LongInt( const string str ) {
	init();
	int i;
	while(i < str.length && str[i]!='0')
		i++;
	while(i < str.length) {
		if(isdigit(str[i]))
			digits.addBack(str[i]);
		i++;
	}
}
LongInt::LongInt( const LongInt &rhs ) {
	init();
	digits.clear();
	while(!rhs->digits.isEmpty()) {

	}
}
LongInt::LongInt( ) {
	init();
}

void LongInt::init() {
	digits = new Deque<char>();
	negative = 0;
}

// Destructor
LongInt::~LongInt( ) {

}

// Arithmetic binary operators
LongInt LongInt::operator+( const LongInt &rhs ) const {

}
LongInt LongInt::operator-( const LongInt &rhs ) const {

}

// assignment operators
const LongInt& LongInt::operator=( const LongInt &rhs ) const{

}

// Logical binary operators
bool LongInt::operator< ( const LongInt & rhs ) const {}
bool LongInt::operator<=( const LongInt & rhs ) const {}
bool LongInt::operator> ( const LongInt & rhs ) const {}
bool LongInt::operator>=( const LongInt & rhs ) const {}
bool LongInt::operator==( const LongInt & rhs ) const {}
bool LongInt::operator!=( const LongInt & rhs ) const {}

void LongInt::remove0s() { }

ostream& operator<<(ostream& out, const LongInt& w) {
	while(!w.digits.isEmpty()) {
		string output;
		output<<digits.
	}
}

// Overloaded >> operator. Takes two integers and sets the appropriate fields
istream& operator>>(istream& in, LongInt& rhs) {
}
