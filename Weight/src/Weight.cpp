/*
  CSS 342 HW1
  Jay Hennen
  Weight.cpp
  9/28/2012
  This class is the implementation of a 'Weight' object which records in lbs
  and ounces. All standard operators are overloaded, and two utility functions,
  getPounds and getOunces are available.
*/

#include "Weight.h"

// Default constructor
Weight::Weight() {
	wt=0;
}

// Constructs a weight object given a number in ounces.
Weight::Weight(int w = 0) {
	wt=w*16;
}

// Constructs a weight object given a number in lbs and ozs.
Weight::Weight(int lb = 0, int oz = 0) {
	wt = lb*16 + oz;
}

// Constructs given a double. Treats decimals as parts of a whole lb
Weight::Weight(double w) {
	wt = w*10000/625;
}

// Constructs given a float
Weight::Weight(float w) {
	wt = w*10000/625;
}

// Returns the number of pounds
int Weight::getPounds(){
	return wt/16;
}

// Returns the number of ounces
int Weight::getOunces(){
	return wt%16;
}

// Overloaded + operator. Depends on +=
Weight Weight::operator+(const Weight &rt) const{
	Weight result= *this;
	result+=rt;
	return result;
}

// Overloaded - operator. Depends on -=
Weight Weight::operator-(const Weight &rt) const{
	Weight result= *this;
	result-=rt;
	return result;
}

// Overloaded * operator for double. Depends on
Weight Weight::operator*(const double &rt) const{
	Weight result= *this;
	result.wt*=rt;
	return result;
}

// Overloaded / operator for double. Displays error if DV0 and depends on /=
Weight Weight::operator/(const double &rt) const{
	if (rt==0) {
			cout << "DIVIDE BY ZERO";
	}
	Weight result= *this;
	result.wt/=rt;
	return result;
}


//Overloaded / operator, warns on DV0
double Weight::operator/(const Weight &rt) const{
	if (rt.wt==0) {
			cout << "DIVIDE BY ZERO";
	}
	return (wt)/(rt.wt*1.0);
}

// Overloaded unary - operator
Weight Weight::operator-() const{
	Weight result= *this;
	result.wt=-wt;
	return result;
}

// This object > parameter ?
bool Weight::operator>(const Weight &rt) const {
	return wt > rt.wt;
}

// This object < parameter ?
bool Weight::operator<(const Weight &rt) const {
	return wt < rt.wt;
}

// This object >= parameter ?
bool Weight::operator>=(const Weight &rt) const {
	return wt >= rt.wt;
}

// This object <= parameter ?
bool Weight::operator<=(const Weight &rt) const {
	return wt <= rt.wt;
}

// This object == parameter ?
bool Weight::operator==(const Weight &rt) const{
	return wt == rt.wt;
}

// This object != parameter ?*/
bool Weight::operator!=(const Weight &rt) const{
	return wt != rt.wt;
}

//
Weight& Weight::operator+=(const Weight &rt) {
	if(this != &rt) {
		wt+=rt.wt;
	}
	return *this;
}

// Overloaded -= operator.
Weight& Weight::operator-=(const Weight &rt) {
	if(this != &rt) {
		wt-=rt.wt;
	}
	return *this;
}

// Overloaded *= operator.
Weight& Weight::operator*=(const double &rt) {
	wt*=rt;
	return *this;
}

// Overloaded /= operator. Warns of DV0.
Weight& Weight::operator/=(const double &rt) {
	if(&rt!=0) {
		wt/=rt;
	} else {
		cout<<"DIVIDE BY ZERO";
	}
	return *this;
}

// Overloaded << operator. Formats the output correctly.
ostream& operator<<(ostream& output, const Weight& w) {
	int lb = w.wt/16;
	int oz = w.wt%16;
	if(lb == 0 && oz == 0) {
		output << "0 oz";
	} else {
		if (lb!=0){
			output << lb << " lb";
		}
		if (lb!=0 && oz!=0) {
			cout << " ";
		}
		if (oz!=0) {
			output << oz << " oz";
		}
	}
	return output;
}

// Overloaded >> operator. Takes two integers and sets the appropriate fields
istream& operator>>(istream& input, Weight& w) {
	int lbs, ozs;
	input >> lbs;
	input >> ozs;
	w.wt=(lbs*16+ozs);
	return input;
}
