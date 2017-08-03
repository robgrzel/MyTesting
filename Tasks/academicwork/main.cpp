//
// Created by robgrzel on 26.07.17.
//


#include "problem_A.h"
#include "problem_B.h"
#include "problem_C.h"

int main() {
	if (RunTests == 2) {
		return problem_A();
	} else if (RunTests == 3) {
		int n, k;
		std::vector <int> T;
		n = 2;
		k = 1;
		
		T = {0, 1000};
		
		problem_B(n, k, T);
		
		
		n = 3;
		k = 2;
		
		T = {1000, 1010, 1999};
		
		problem_B(n, k, T);
		
		
		return 0;
	} else if (RunTests == 4) {
		
		int numTestcases, c, d, v;
		std::vector <std::pair<int,int>> V;
		
		numTestcases = 2;
		c = 1;
		d = 1;
		v = 2;
		//(-) cats, (+) dogs
		V = {
				{-1,1},
				{1,-1},
				
		};
		
		problem_C(numTestcases, c, d, v, V);
		
		c = 1;
		d = 2;
		v = 4;
		//(-) cats, (+) dogs
		//left win, right lose
		V = {
				{-1,1},
				{-1,1},
				{-1,2},
				{2,-1}
			
		};
		
		
		
		problem_C(numTestcases, c, d, v, V);
		
		
		return 0;
		
	} else if (RunTests == -1) {
		problem_A();
		int n, k;
		std::vector <int> T;
		n = 2;
		k = 1;
		
		T = {0, 1000};
		
		problem_B(n, k, T);
		
		n = 3;
		k = 2;
		
		T = {1000, 1010, 1999};
		
		problem_B(n, k, T);
		//problem_C();
		return 0;
	}
	
	return 0;
}