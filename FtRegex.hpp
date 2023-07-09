#ifndef FT_REGEX_FTREGEX_HPP
#define FT_REGEX_FTREGEX_HPP

#include <regex.h>
#include <string>
#include <exception>
#include <cstring>
#include <cstdlib>

class FtRegex
{
private:
	static regex_t _preg;
	static regmatch_t _rmatch;

	FtRegex();                                  //canonical form, 42 subject requirement
	FtRegex(const FtRegex &src);                //canonical form, 42 subject requirement
	FtRegex &operator=(const FtRegex &src);     //canonical form, 42 subject requirement
	~FtRegex();                                 //canonical form, 42 subject requirement
public:
	static bool    matchRegex(const std::string &pattern, const std::string &string);

	class RegCompFailedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};


#endif //FT_REGEX_FTREGEX_HPP
