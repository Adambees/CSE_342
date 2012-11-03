/*
 ============================================================================
 Name        : Hello.cpp
 Author      : Jay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

void test(int &x) {
	cout << x << " words\n";
	x = 5;
}

void test(string &s) {
	cout << s << endl;
	s = "string2";
}

void swap(vector<int> &v, int x, int y) {
	int temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}


int main(void) {
	cout << "Hello World" << endl; /* prints Hello World */
	cout << 5+5 << endl;
	int x = 15;
	string s = "string";
	test(x);
	cout << x << " words\n";
	test(s);
	cout << s << endl;
	vector<int> v(2);
	v[0]=0;
	v[1]=1;
	cout << v[0]<< " " << v[1] << endl;
	swap(v,0,1);
	cout << v[0]<< " " << v[1] << endl;
	cout << -17 / 16 << endl;
	return 0;
}


