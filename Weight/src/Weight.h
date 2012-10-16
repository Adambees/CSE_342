/*
  CSS 342 HW1
  Jay Hennen
  Weight.h
  9/28/2012
  This class is the header of a 'Weight' object which records in lbs
  and ounces. All standard operators are available, and two utility functions,
  getPounds and getOunces are available.
*/
#ifndef WEIGHT_H
#define WEIGHT_H
#include <iostream>
using namespace std;
class Weight {
public:
	Weight();
	Weight(int w);
	Weight(int, int);
	Weight(double w);
	Weight(float w);
	int getPounds();
	int getOunces();
	Weight operator+(const Weight &) const;	// arithmetic operators:this object + parameter
	Weight operator-(const Weight &) const;	// 		this object –  parameter
	Weight operator*(const double &) const;	// 		this object * parameter
	double operator/(const Weight &) const;		// 		this object / parameter
	Weight operator/(const double &) const;		// 		this object / parameter
	Weight operator-() const;		// 		this object / parameter
	bool operator>(const Weight &) const;	// boolean comparison operators: 	this object > parameter ?
	bool operator<(const Weight &) const;	// 			this object < parameter ?
	bool operator>=(const Weight &) const;	//			this object >= parameter ?
	bool operator<=(const Weight &) const;	//			this object >= parameter ?
	bool operator==(const Weight &) const;	//			this object == parameter ?
	bool operator!=(const Weight &) const;	//			this object != parameter ?
	Weight& operator+=(const Weight &);	// assignment operators:	this object += parameter
	Weight& operator-=(const Weight &);	// assignment operators:	this object -= parameter
	Weight& operator*=(const double &);	// assignment operators:	this object -= parameter
	Weight& operator/=(const double &);	// assignment operators:	this object -= parameter
	friend ostream& operator<<(ostream& output, const Weight & w);
	friend istream& operator>>( istream& input, Weight & w);
private:
	int wt;
};

#endif
