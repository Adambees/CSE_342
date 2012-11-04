#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

template <class Comparable>
void merge(vector<Comparable> &A, vector<Comparable> &B, int left, int right, int end) {
	int li = left;
	int ri = right;

	/* while there are elements in the left or right lists
	 * start at left, go to end*/
	for (int j = left; j < end; j++)
	{
		/* if left list head exists and is <= existing right list head */
		if (li < right && (ri >= end || A[li] <= A[ri])) {
			B[j] = A[li]; // choose number from left sub-array
			li = li + 1;  // shift
		} else {
			B[j] = A[ri]; // choose number from right sub-array
			ri = ri + 1;  // shift
		}
	}
}

template <class Comparable>
void mergesort( vector<Comparable> &a ) {

	int size = a.size( );
	vector<Comparable> b( size );  // this is only one temporary array.

	// implement a nonrecursive mergesort only using vectors a and b.

	int len; // length of sub-arrays
	for(len = 1; len < size; len = 2*len) {
		for (int i = 0; i < size; i += 2*len) {
			merge(a, b, i, min(i+len, size), min(i+2*len, size));
		}
		a = b;
	}
}
