//
// Created by nskiba on 7/9/23.
//

#include "FtRegex.hpp"
#include <iostream>
regex_t FtRegex::_preg;
regmatch_t FtRegex::_rmatch;

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

	memset(&_rmatch, 0, sizeof(_rmatch));

	status = regexec(&_preg, string.c_str(), 1, &_rmatch, 0);

	regfree(&_preg);
	return (status == 0 && string.length() == ((size_t)_rmatch.rm_eo - (size_t)_rmatch.rm_so));
}

const char *FtRegex::RegCompFailedException::what() const throw()
{
	return ("Regcomp failed.");
}