/*
 * Distance.cpp
 *
 *  Created on: Sep 28, 2012
 *      Author: jay
 */

#include "Distance.h"
Distance::Distance() {
	dist=0;
}

// Constructs a Distance object given a number in ounces.
Distance::Distance(int d) {
	dist=d*12;
}

// Constructs a Distance object given a number in fts and ins.
Distance::Distance(int ft, int in) {
	dist = ft*12 + in;
}


Distance::Distance(double d) {
	dist = d*10000/625;
}


Distance::Distance(float d) {
	dist = d*10000/625;
}

int Distance::getPounds(){
	return dist/12;
}

int Distance::getOunces(){
	return dist%12;
}

Distance Distance::operator+(const Distance &rt) const{
	Distance result= *this;
	result+=rt;
	return result;
}

Distance Distance::operator-(const Distance &rt) const{
	Distance result= *this;
	result-=rt;
	return result;
}

Distance Distance::operator*(const double &rt) const{
	Distance result= *this;
	result*=rt;
	return result;
}

Distance Distance::operator/(const double &rt) const{
	Distance result= *this;
	result/=rt;
	return result;
}

double Distance::operator/(const Distance &rt) const{
	return (dist)/(rt.dist*1.0);
}

Distance Distance::operator-() const{
	Distance result= *this;
	result.dist=-dist;
	return result;
}

// boolean comparison operators: 	this object > parameter ?
bool Distance::operator>(const Distance &rt) const {
	return dist > rt.dist;
}

// 			this object < parameter ?
bool Distance::operator<(const Distance &rt) const {
	return dist < rt.dist;
}

//			this object >= parameter ?
bool Distance::operator>=(const Distance &rt) const {
	return dist >= rt.dist;
}

//			this object <= parameter ?
bool Distance::operator<=(const Distance &rt) const {
	return dist <= rt.dist;
}

//			this object == parameter ?
bool Distance::operator==(const Distance &rt) const{
	return dist == rt.dist;
}

//			this object != parameter ?*/
bool Distance::operator!=(const Distance &rt) const{
	return dist != rt.dist;
}

//
Distance& Distance::operator+=(const Distance &rt) {
	if(this != &rt) {
		dist+=rt.dist;
	}
	return *this;
}

//
Distance& Distance::operator-=(const Distance &rt) {
	if(this != &rt) {
		dist-=rt.dist;
	}
	return *this;
}

Distance& Distance::operator*=(const double &rt) {
	dist*=rt;
	return *this;
}

Distance& Distance::operator/=(const double &rt) {
	if(&rt!=0) {
		dist/=rt;
	} else {
		cout<<"DIVIDE BY ZERO";
	}
	return *this;
}

ostream& operator<<(ostream& output, const Distance& d) {
	int ft = d.dist/12;
	int in = d.dist%12;
	if(ft == 0 && in == 0) {
		output << "0 in";
	} else {
		if (ft!=0){
			output << ft << " ft";
		}
		if (ft!=0 && in!=0) {
			cout << " ";
		}
		if (in!=0) {
			output << in << " in";
		}
	}
	return output;
}

// Overloaded >> operator. Takes two integers and sets the appropriate fields
istream& operator>>(istream& input, Distance& d) {
	int fts, ins;
	input >> fts;
	input >> ins;
	d.dist=(fts*12+ins);
	return input;
}
