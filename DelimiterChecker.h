#ifndef _DELIMITER_CHECKER_
#define _DELIMITER_CHECKER_
#include "GenStack.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>

class DelimiterChecker
{
	public:
		DelimiterChecker();
		DelimiterChecker(std::string fileName);
		~DelimiterChecker();
		bool CheckFile();

	private:
		char GetOpposite(char input);
		void OpenStream();
		std::string filename;
		GenStack<char> stack;
		GenStack<int> position;
		std::ifstream inf;
};

#endif