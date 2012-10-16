/*
 * Euclid.cpp
 *
 *  Created on: Oct 12, 2012
 *      Author: Jay
 */

#include <iostream>
#include <cmath>
#include <ctime>

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

int main() {
	clock_t start, end;
	int numDP = 40; // initial array size
	int nums[numDP];
	nums[0] = 8;
	// The following for loop writes a series of numbers to the array where nums[i] = nums[i-1]*3/2
	// The loop cuts out after nums[i] goes past 3000 to avoid swamping the CPU with n^2 growth
	for (int i=1; i < numDP; i++) {
		nums[i] = nums[i-1]*3/2;
		if (nums[i] > 7000) {
			numDP = i+1; // set final length of the array for future use
			break;
		}
	}
	for (int dp = 0; dp < numDP; dp++) { // for each n in the array
		int maxCount = 0;
		start = clock();
		for (int i = 8; i <= nums[dp]; i++) { //
			for (int j = i; j <= nums[dp]; j++ ) {
				int c = findGCD(i, j);
				if (c > maxCount) {
					maxCount = c;
				}
			}
		}
		end = clock();
		double elapsed = (double)(end-start)/CLOCKS_PER_SEC;
		cout << "Max was " << maxCount << ", number was: " << nums[dp] <<", elapsed time: " << elapsed << endl;
		cerr << maxCount << " " << nums[dp] << " " << elapsed << endl;
	}

	return 0;
}
