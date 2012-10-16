/*
 * Euclid.cpp
 *
 *  Created on: Oct 12, 2012
 *      Author: Jay
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

long long int toddiff(struct timeval *tod1, struct timeval *tod2)
{
    long long t1, t2;
    t1 = tod1->tv_sec * 1000000 + tod1->tv_usec;
    t2 = tod2->tv_sec * 1000000 + tod2->tv_usec;
    return t1 - t2;
}

int main() {
	int n;
	cin >> n;
	for (int i = 8; i <= n; i++) { // for each n in the array
		struct timeval start, end;
		int maxCount = 0;
		gettimeofday(&start,NULL);
		for (int j = 8; j <= i; j++) { //
			for (int k = j+1; k <= i; k++ ) {
				int c = findGCD(j, k);
				if (c > maxCount) {
					maxCount = c;
				}
			}
		}
		gettimeofday(&end,NULL);
		cout << "Max was " << maxCount << ", number was: " << i <<", elapsed time: " << toddiff(&end,&start) << endl;
		cerr << maxCount << " " << i << " " << toddiff(&end,&start) << endl;
	}

	return 0;
}
