#include <iostream>
#include "FtRegex.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: /regextest <regex> <string>" << std::endl;
		exit(0);
	}

	try {
		if(FtRegex::matchRegex(argv[1], argv[2]))
			std::cout << "regex !!\n";
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
