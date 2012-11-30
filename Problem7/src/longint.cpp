/*
 ============================================================================
 Name        : Problem7.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include "longint.h"

// Constructors
LongInt::LongInt( const string str ) {
	init();
	addDigits(str);
}
LongInt::LongInt( const LongInt &rhs ) {
	init();
	digits.clear();
	while(!rhs.digits.isEmpty()) {

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
	return NULL;
}
LongInt LongInt::operator-( const LongInt &rhs ) const {
	return NULL;
}

// assignment operators
const LongInt& LongInt::operator=( const LongInt &rhs ) {
	return NULL;
}

// Logical binary operators
bool LongInt::operator< ( const LongInt & rhs ) const { return 1;}
bool LongInt::operator<=( const LongInt & rhs ) const {return 1;}
bool LongInt::operator> ( const LongInt & rhs ) const {return 1;}
bool LongInt::operator>=( const LongInt & rhs ) const {return 1;}
bool LongInt::operator==( const LongInt & rhs ) const {return 1;}
bool LongInt::operator!=( const LongInt & rhs ) const {return 1;}

void LongInt::remove0s() { }

void LongInt::addDigits(const string str) {
	int i;
		while(i < str.length && str[i] <= '0' && str[i] > '9') {
			if (str[i] == '-')
				negative = 1;
			i++;
		}
		while(i < str.length) {
			if(isdigit(str[i]))
				digits.addBack(str[i]);
			i++;
		}
}

ostream& operator<<(ostream& out, const LongInt& w) {
	string output;
	while(!w.digits.isEmpty())
		output << w.digits.removeFront();
	out << output;
	return out;
}

// Overloaded >> operator. Takes two integers and sets the appropriate fields
istream& operator>>(istream& in, LongInt& rhs) {
	string input;
	in >> input;
	rhs.addDigits(input);
	return in;
}
