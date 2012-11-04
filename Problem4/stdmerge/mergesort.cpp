#include <vector>
using namespace std;

template <class Comparable>
void merge( vector<Comparable> &a, int first, int mid, int last ) {
  vector<Comparable> tempArray( a.size( ) );
  int first1 = first; int last1 = mid;         // the left array[first1..last1]
  int first2 = mid + 1; int last2 = last;     // the right array[first2..last2]

  int index = first1;
  for ( ; first1 <= last1 && first2 <= last2; ++index ) // choose a smaller
    tempArray[index] = ( a[first1] < a[first2] ) ? a[first1++] : a[first2++];
  
  for ( ; first1 <= last1; ++first1, ++index )      // exhaust the left array
    tempArray[index] = a[first1];

  for ( ; first2 <= last2; ++first2, ++index )      // exhaust the right array
    tempArray[index] = a[first2];

  for ( index = first; index <= last; ++index )  // write them back to original
    a[index] = tempArray[index];
}

template <class Comparable>
void mergesort( vector<Comparable> &a, int first, int last ) {

  if ( first < last ) {
    int mid = ( first + last ) / 2;              // divide the array into two
    mergesort( a, first, mid );                  // sort the left array
    mergesort( a, mid + 1, last );               // sort the right array
    merge( a, first, mid, last );                // merge them into one
  }
}

template <class Comparable>
void mergesort( vector<Comparable> &a ) {        // the driver
  mergesort( a, 0, a.size( ) - 1 );
}
