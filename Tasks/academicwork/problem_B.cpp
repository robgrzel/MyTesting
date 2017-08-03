#ifndef RunTests
	
	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <sstream>
	#include <iomanip>
	#include <iterator>
	#include <cmath>
	#include <cstring>

#else
	
	#include "problem_B.h"

#endif


int problem_B(
#ifdef RunTests
		int n, int k, std::vector <int> T
#endif
) {
	
	/*
	 * n - number of requests;
	 * k - max number or requests per second that each server can handle
	 * t - vector of ti;
	 * ti - ith request happen ti miliseconds from moment of notifying custormers
	 *    - time delay before doing request
	 */
	
	
	#ifndef RunTests
	
	int n, k;
	
	std::cin >> n >> k;
	
	if (n > 100000)
		n = 100000;
	else if (n < 1){
		std::cout<<0<<std::endl;
		return 0;
	}
	
	if (k > 100000)
		k = 100000;
	else if (k < 1){
		std::cout<<0<<std::endl;
		return 0;
	}
	
	std::vector <int> T(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> T[i];
	}
	
	#else
	
	std::cout << "########################\n";
	std::cout << n << "," << k << "\n";
	
	#endif
	
	int tmax = 0;
	for (int t: T) {
		tmax = std::max(tmax, t);
	}
	
	int t = 0;
	int maxReqInTi = 0;
	std::vector <int> reqInTi(tmax, 0);
	
	for (int i = 0; i < n; i++) {
		t = T[i];
		for (int j = 0; j < 1000; j++) {
			reqInTi[t + j]++;
			maxReqInTi = std::max(maxReqInTi, reqInTi[t + j]);
		}
	}
	
	int numServers;
	
	numServers = (int) ceil((double) maxReqInTi / (double) k);
	
	std::cout << numServers << std::endl;
	
	return 0;
}


#ifndef RunTests

int main() {
	
	
	return problem_B();
	
	
}

#endif