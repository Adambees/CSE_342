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
#include "cmath"

//	 Constructors
LongInt::LongInt( const string str ) {
	negative = 0;
	addDigits(str);
}
LongInt::LongInt( const LongInt &rhs ) {
	negative = rhs.negative;
	digits.clear();
	Deque<char>d(rhs.digits);
	while(!d.isEmpty()) {
		digits.addBack(d.removeFront());
	}
}
LongInt::LongInt( ) {
	negative = 0;
}

LongInt::~LongInt( ) {
	digits.clear();
}

void LongInt::convertSign() {
	int i = 0;
	while (i < digits.size()) {
		char c =(char)( 9 -((int)digits.removeFront() - 48) + 48);
		digits.addBack(c);
		i++;
	}
	negative = !negative;
}


// Arithmetic binary operators
LongInt LongInt::operator+( const LongInt &rhs ) const {
	LongInt result;
	if(negative == rhs.negative) {
		if (negative) {
			LongInt left(*this);
			LongInt right(rhs);
			left.convertSign();
			right.convertSign();
			result =  left + right;
			result.convertSign();
			return result;
		}
		Deque<char> r(rhs.digits); //right side
		Deque<char> l(digits); //left side

		int i = 0;
		int carry = 0;
		while (i < max(r.size(), l.size())) {
			int sum;
			int lval;
			int rval;
			(!l.isEmpty()) ? lval = (int)l.removeBack() - 48 : lval = 0;
			(!r.isEmpty()) ? rval = (int)r.removeBack() - 48 : rval = 0;
			sum = lval + rval + carry;
			carry = sum / 10;
			result.digits.addFront((char)(sum % 10 + 48));
		}
		if (carry)
			result.digits.addFront('1');

	} else {
		if (rhs.negative) { // this positive rhs negative
			LongInt temp(rhs);
			temp.convertSign();
			result = operator-(temp);
		} else { // this negative rhs positive
			LongInt temp((*this));
			temp.convertSign();
			result = rhs.operator-(temp);
		}
	}
	return result;
}

LongInt LongInt::operator-( const LongInt &rhs ) const {
	LongInt result;
	if(negative == rhs.negative) {
		if ((*this) <= rhs && !negative) {
			LongInt subtrahend(rhs);
			subtrahend.convertSign();
			subtrahend.negative = 0;
			result = (*this)+subtrahend;
			result.negative = 1;
		} else if ((*this) > rhs && !negative) {
			LongInt minuend((*this));
			minuend.convertSign();
			minuend.negative = 0;
			result = minuend+rhs;
			result.negative = 1;
			result.convertSign();
		} else if ((*this) <= rhs && negative) {
			LongInt minuend((*this));
			minuend.negative = 0;
			LongInt subtrahend(rhs);
			subtrahend.convertSign();
			result = minuend+subtrahend;
			result.negative = 1;
		} else {
			LongInt minuend((*this));
			minuend.convertSign();
			LongInt subtrahend(rhs);
			subtrahend.negative = 0;
			result = minuend+subtrahend;
			result.negative = 1;
			result.convertSign();
		}
		result.remove0s();
	} else {
		if (negative && !rhs.negative){
			LongInt temp(rhs);
			temp.convertSign();
			result = (*this) + (temp);
		}
		if (!negative && rhs.negative) {
			LongInt temp(rhs);
			temp.convertSign();
			result = (*this) +(temp);
		}
	}

	return result;
}
//
// assignment operators
const LongInt& LongInt::operator=( const LongInt &rhs ) {
	if (this != &rhs) {
		digits.clear();
		(*this).digits = rhs.digits;
		negative = rhs.negative;
	}
	return *this;
}
//
// Logical binary operators
bool LongInt::operator< ( const LongInt & rhs ) const {
	if (operator==(rhs)) // lhs.negative -> rhs.negative
		return false;
	else {
		if (negative != rhs.negative)
			return negative;
		if (digits.size() != rhs.digits.size())
			return digits.size() > rhs.digits.size() == negative;
		else {
			Deque<char> r(rhs.digits); //right side
			Deque<char> l(digits); //left side

			int i = 0;
			// numbers have same sign, equal length, so iterate and compare
			while (i < max(r.size(), l.size())) {
				int lval;
				int rval;
				(!l.isEmpty()) ? lval = (int)l.removeFront() : lval = -1;
				(!r.isEmpty()) ? rval = (int)r.removeFront() : rval = -1;
				if (negative && lval != rval)
					return lval < rval;
				if (!negative && lval != rval)
					return lval < rval;

			}
		}
	}
	return false;
}
bool LongInt::operator==( const LongInt & rhs ) const {
	if (negative == rhs.negative) {
		Deque<char> * r = new Deque<char>(rhs.digits); //right side
		Deque<char> * l = new Deque<char>(digits); //left side

		int i = 0;
		while (i < max(r->size(), l->size())) {
			int lval;
			int rval;
			(!l->isEmpty()) ? lval = (int)l->removeFront() : lval = -1;
			(!r->isEmpty()) ? rval = (int)r->removeFront() : rval = -1;
			if (lval == -1 || rval == -1 )
				return false;
			if (!(lval == rval))
				return false;
		}
		return true;
	} else {
		return false;
	}
}
bool LongInt::operator!=( const LongInt & rhs ) const {
	return !operator==(rhs);
//	return false;
}
bool LongInt::operator<=( const LongInt & rhs ) const {
	return ( operator==(rhs) || operator<(rhs));
}
bool LongInt::operator> ( const LongInt & rhs ) const {
	return !(operator<=(rhs));
}
bool LongInt::operator>=( const LongInt & rhs ) const {
	return !(operator<(rhs));
}

void LongInt::remove0s() {
	while (!digits.isEmpty() && negative && digits.getFront()=='9')
		digits.removeFront();
	while (!digits.isEmpty() && !negative && digits.getFront()=='0')
		digits.removeFront();
}

// This method adds digits from an input string to the deque. If the string indicates a negative
// number, then the number will be converted into 9s complement format
// For example, -1 would be stored as 8, with the negative flag set
// -10 would be stored as 89
void LongInt::addDigits(const string str) {
	int i;
		while(i < str.length() && (str[i] <= '0' || str[i] > '9')) {
			if (str[i] == '-')
				negative = 1;
			i++;
		}
		while(i < str.length()) {
			if (isdigit(str[i])){
				if (negative)
					digits.addBack((char)(105 - (int)str[i])); // this is the 9s complement of the digit
				else
					digits.addBack(str[i]);
			}
			i++;
		}
}

ostream& operator<<(ostream& out, const LongInt& rhs) {
	if (rhs.digits.isEmpty()) {
		out << '0';
		return out;
	}
	if(rhs.negative)
		out << '-';
	Deque<char> d(rhs.digits);
	while(!d.isEmpty()) {
		if (rhs.negative) {
			out << (char)(105 - d.removeFront());
		} else {
			out << d.removeFront();
		}
	}
	return out;
}

//
istream& operator>>(istream& in, LongInt& rhs) {
	string input;
	in >> input;
	rhs.addDigits(input);
	return in;
}
