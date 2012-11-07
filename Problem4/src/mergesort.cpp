/*
  CSS 342 HW3
  Jay Hennen
  mergesort.cpp
  11/4/2012
  This is an implementation of the bottom up merge sort algorithm, conducted
  iteratively to increase speed.
 */

#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

// Method to merge two subsections of vector a into vector b.
// The length of subsections is right - left. 'end' denotes either the last
// element in the array, or the start of the next pair of subsections
template <class Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &b, int left, int right, int end) {
	int li = left;
	int ri = right;

/* j is the index of array b that is being written to*/
	for (int j = left; j < end; j++)
	{
		/*If left index is still within it's subsection, and right index
		 * has passed the end OR left element is less than right element*/
		if (li < right && (ri >= end || a[li] <= a[ri])) {
			b[j] = a[li]; // choose number from left sub-array
			li = li + 1;  // shift left index
		} else {
			b[j] = a[ri]; // choose number from right sub-array
			ri = ri + 1;  // shift right index
		}
	}
}

template <class Comparable>
void mergesort( vector<Comparable> &a ) {

	int size = a.size( );
	vector<Comparable> b( size );  // this is only one temporary array.

	// implement a nonrecursive mergesort only using vectors a and b.

	int len; // length of sub-arrays
	vector<Comparable> temp;
	for(len = 1; len < size; len = 2*len) {		// l = index of left subsection
		for (int l = 0; l < size; l += 2*len) {
			int r = min(l+len, size);			// r = index of right subsection
			int end = min(l+2*len, size);		// end = index of next sub or end of vector
			merge(a, b, l, r, end);			// merge left and right subsections
		}
		temp = a;
		a = b;
		b = temp;
	}

}
