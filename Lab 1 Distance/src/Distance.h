// A Distance class                                    // Munehiro Fukuda
#ifndef DISTANCE_H                                     // CSS342
#define DISTANCE_H
#include <iostream>
using namespace std;

typedef int Inch;
typedef int Feet;
typedef double Sqfeet;

class Distance {
public:
	Distance();
	Distance(int w);
	Distance(int lb, int oz);
	Distance(double w);
	Distance(float w);
	int getPounds();
	int getOunces();
	Distance operator+(const Distance &) const;	// arithmetic operators:this object + parameter
	Distance operator-(const Distance &) const;	// 		this object –  parameter
	Distance operator*(const double &) const;	// 		this object * parameter
	double operator/(const Distance &) const;		// 		this object / parameter
	Distance operator/(const double &) const;		// 		this object / parameter
	Distance operator-() const;		// 		this object / parameter
	bool operator>(const Distance &) const;	// boolean comparison operators: 	this object > parameter ?
	bool operator<(const Distance &) const;	// 			this object < parameter ?
	bool operator>=(const Distance &) const;	//			this object >= parameter ?
	bool operator<=(const Distance &) const;	//			this object >= parameter ?
	bool operator==(const Distance &) const;	//			this object == parameter ?
	bool operator!=(const Distance &) const;	//			this object != parameter ?
	Distance& operator+=(const Distance &);	// assignment operators:	this object += parameter
	Distance& operator-=(const Distance &);	// assignment operators:	this object -= parameter
	Distance& operator*=(const double &);	// assignment operators:	this object -= parameter
	Distance& operator/=(const double &);	// assignment operators:	this object -= parameter
	friend ostream& operator<<(ostream& output, const Distance &);
	friend istream& operator>>( istream& input, Distance &);
private:
	int dist;
};
#endif
