#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

template <class Comparable>
void merge( vector<Comparable> &b, int n1, int n2 , int len) {

}

template <class Comparable>
void mergesort( vector<Comparable> &a ) {

	int size = a.size( );
	vector<Comparable> b( size );  // this is only one temporary array.

	// implement a nonrecursive mergesort only using vectors a and b.



	int len = 1; // length of sub-arrays
	for(len < size)
	for(int i = 0, j = size/2-len; i < size/2-len && j < size; i+=2*len, j+=2*len) {
		merge( a, i,i+len, len);
	}

}
