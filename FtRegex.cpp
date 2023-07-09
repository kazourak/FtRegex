//
// Created by nskiba on 7/9/23.
//
#include <iostream>

#include "FtRegex.hpp"
regex_t FtRegex::_preg;

/**
 * Performs a perfect match between a regular expression pattern and a string.
 *
 * @param pattern The regular expression pattern to match.
 * @param string The string to be matched against the pattern.
 * @return True if the pattern matches the entire string, False otherwise.
 */
bool FtRegex::matchRegex(const std::string &pattern, const std::string &string)
{
	int status;

	if (regcomp(&_preg, pattern.c_str(), REG_EXTENDED) != 0)
		throw FtRegex::RegCompFailedException();

	status = regexec(&_preg, string.c_str(), 0, NULL, 0);
	regfree(&_preg);
	return (status == 0);
}

const char *FtRegex::RegCompFailedException::what() const throw()
{
	return ("Regcomp failed.");
}