/*
  CSS 342 HW2
  Jay Hennen
  Weight.cpp
  10/13/2012
  This class is runs Euclid's Algorithm for all pairs of numbers between 8 and n. It tracks
  and outputs the max modulus operations required to find the GCD between two pairs of numbers
  8 and n. It outputs those numbers i and j and also their GCD. Lastly, it also records the time
  it takes for the program to complete all iterations of Euclid's Algorithm for all pairs of numbers
  between 8 and n.
*/

#include <iostream>
#include <cmath>
#include <sys/time.h>

using namespace std;

/*
 * This function finds the GCD of two integers using Euclid's algorithm and returns
 * the number of modulus operations it took
*/
int findGCD(int i, int j) {
	int count = 0;
	while( j != 0) {
		int r = j;
		j = i % j;
		count ++;
		i = r;
	}
	return count;
}

// function to subtract one timeval from the other
long long int elapsed(struct timeval *td1, struct timeval *td2)
{
    long long t1, t2;
    t1 = td1->tv_sec * 1000000 + td1->tv_usec;
    t2 = td2->tv_sec * 1000000 + td2->tv_usec;
    return t1 - t2;
}

int main() {
	int n = 0;
	while (n <= 8) {
		cout << "Please input an n > 8: ";
		cin >> n;
	}
	for (int i = 8; i <= n; i++) {
		struct timeval start, end;
		int maxCount = 0;
		int n1=0,n2=0;
		gettimeofday(&start,NULL);				//start timing
		for (int j = 8; j <= i; j++) {
			for (int k = j+1; k <= i; k++ ) {
				int c = findGCD(j, k);
				if (c > maxCount) {
					maxCount = c;
					n1=j;
					n2=k;
				}
			}
		}
		gettimeofday(&end,NULL);
		cout << "Max was " << maxCount << ", i was " << n1 << ", j was " << n2 <<
				", n was: " << i <<", elapsed time: " << elapsed(&end,&start) << endl;
		cerr << maxCount << " " << i << " " << elapsed(&end,&start) << endl;
	}

	return 0;
}
