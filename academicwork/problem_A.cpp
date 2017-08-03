#ifndef RunTests
	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <sstream>
	#include <iomanip>
#else
	
	#include "problem_A.h"

#endif


int problem_A() {
	/*
	INPUT:
	* std input
	* max 10,000.0 characters
	* line of text end with \n
	* text is ASCII 9 ([tab]) and in range 32 - 126 (from [space] to [~])
	COMPUT:
	* only alphabetic characters should be translated, rest printed without modifying
	OUTPUT:
	* text with each letter (lower/upper cases) translated to new alphabet;
	 * std output
*/
	
	std::string line;
	
	#ifdef RunTests
	line = "Hello  ~World! ta \\t";
	#else
	
	char c;
	for (int i = 0; i < 10000; i++) {
		std::cin >> std::noskipws >> c;
		if (c == '\n')
			break;
		line.push_back(c);
	}
	#endif
	
	//std::getline(std::cin, line,'\n'); //cant limit to 10000 :(
	
	#ifdef RunTests
	std::cout << line << std::endl;
	#endif
	
	const char mydict[26][7] = {
			"@", "8", "(", "|)", "3",
			"#", "6", "[-]", "|", "_|",
			"|<", "1", "[]\\/[]", "[]\\[]", "0",
			"|D", "(,)", "|Z", "$", "']['",
			"|_|", "\\/", "\\/\\/", "}{", "`/",
			"2"};
	
	
	std::transform(line.begin(), line.end(), line.begin(), ::tolower);
	
	std::string out;
	
	for (const char c: line) {
		int i = c % 97;
		if (c == '\t' or i < 0 or i > 25) {
			out += c;
		} else {
			out += mydict[i];
		}
		
		
	}
	
	std::cout << out << std::endl;
	
	return 0;
	
	
}

#ifndef RunTests
int main() {
	
	
	return problem_A();
	
	
}
#endif