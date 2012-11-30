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
	init();
	addDigits(str);
}
LongInt::LongInt( const LongInt &rhs ) {
	init();
	digits.clear();
	Deque<char> * d= new Deque<char>(rhs.digits);
	while(!d->isEmpty()) {
		digits.addBack(d->removeFront());
	}
	delete(d);
}
LongInt::LongInt( ) {
	init();
}

LongInt::~LongInt( ) {
	digits.clear();
}

void LongInt::init() {
	negative = 0;
}


// Arithmetic binary operators
LongInt LongInt::operator+( const LongInt &rhs ) const {
	LongInt result;
	if(negative == rhs.negative) {
		Deque<char> * r = new Deque<char>(rhs.digits); //right side
		Deque<char> * l = new Deque<char>(digits); //left side

		int i = 0;
		int carry = 0;
		while (i < max(r->size(), l->size())) {
			int sum;
			int lval;
			int rval;
			(!l->isEmpty()) ? lval = (int)l->removeBack() - 48 : lval = 0;
			(!r->isEmpty()) ? rval = (int)r->removeBack() - 48 : rval = 0;

			sum = lval + rval + carry;
			carry = sum / 10;
			result.digits.addFront((char)(sum % 10 + 48));


		}
		if (carry)
			result.digits.addFront('1');
		if (negative)
			result.negative = 1;

	} else {
		if (rhs.negative) {
			LongInt temp(rhs);
			temp.negative = 0;
			result = operator-(rhs);
		} else {
			result = rhs.operator-(*this);
		}
	}
	return result;
}
LongInt LongInt::operator-( const LongInt &rhs ) const {
	LongInt result;
	if(negative == rhs.negative) {
			Deque<char> * r = new Deque<char>(rhs.digits); //right side
			Deque<char> * l = new Deque<char>(digits); //left side

			int i = 0;
			int borrow = 0;
			while (i < max(r->size(), l->size())) {
				int sum;
				int lval;
				int rval;
				(!l->isEmpty()) ? lval = (int)l->removeBack() - 48 : lval = 0;
				(!r->isEmpty()) ? rval = (int)r->removeBack() - 48 : rval = 0;

				sum = lval - rval - borrow;
				if (sum < 0) {
					sum = sum+10;
					borrow = 1;
					result.digits.addFront((char)((sum)%() + 48));
				} else {
					result.digits.addFront((char)((sum)%10 + 48));
				}


			}
			if (borrow) {
				result.negative = 1;
			}

	} else {
		if (negative && !rhs.negative)
			result = operator+(rhs);
		if (!negative && rhs.negative) {
			LongInt temp(rhs);
			temp.negative = 0;
			result = operator+(temp);
		}
	}
	return result;
}
//
//// assignment operators
//const LongInt& LongInt::operator=( const LongInt &rhs ) {
//	return NULL;
//}
//
// Logical binary operators
bool LongInt::operator< ( const LongInt & rhs ) const {
	if (operator==(rhs)) // lhs.negative -> rhs.negative
		return false;
	else {
		if (digits.size() < rhs.digits.size())
			// both negative, or left + right - return false
			return !((negative && rhs.negative) || (!negative && rhs.negative));
		else if (digits.size() > rhs.digits.size())
			// both positive or left - right + return true
			return ((!negative && !rhs.negative) || (negative && !rhs.negative));
		else {
			if ((negative && !rhs.negative) || (negative != rhs.negative))
				return true; // eliminates same length different sign case
			else {
				Deque<char> * r = new Deque<char>(rhs.digits); //right side
				Deque<char> * l = new Deque<char>(digits); //left side

				int i = 0;
				// numbers have same sign, equal length, so iterate and compare
				while (i < max(r->size(), l->size())) {
					int lval;
					int rval;
					(!l->isEmpty()) ? lval = (int)l->removeFront() : lval = -1;
					(!r->isEmpty()) ? rval = (int)r->removeFront() : rval = -1;
					if (lval < rval)
						return !negative;
					if (lval > rval)
						return negative;
				}
				return false; // numbers are equal
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

void LongInt::remove0s() { }

void LongInt::addDigits(const string str) {
	int i;
		while(i < str.length() && (str[i] <= '0' || str[i] > '9')) {
			if (str[i] == '-')
				negative = 1;
			i++;
		}
		while(i < str.length()) {
			if(isdigit(str[i]))
				digits.addBack(str[i]);
			i++;
		}
}

ostream& operator<<(ostream& out, const LongInt& rhs) {
	if(rhs.negative)
		out << '-';
	Deque<char> * d= new Deque<char>(rhs.digits);
	while(!d->isEmpty())
		out << d->removeFront();
	delete(d);
	return out;
}

// Overloaded >> operator. Takes two integers and sets the appropriate fields
istream& operator>>(istream& in, LongInt& rhs) {
	string input;
	in >> input;
	rhs.addDigits(input);
	return in;
}
