#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <string>
#include <fstream>
#include <sstream>

namespace json
{
	bool isNum(char c)
	{
       return ((c >= '0') && (c<= '9')) || (c == '.');
	}

	bool firstAndLastMatch(const std::string str, char first, char last)
	{
		return (str[0] == first && str[str.length() - 1] == last)
	}

	bool strContains(const std::string str, char c)
	{
		return str.find(c) != std::string::npos;
	}

	bool isEmpty(const string str)
	{
		return (c == ' ')||(c == '\n')||(c == '\t');
	}

	static std::string readFile (const char * filename)
	{
		std::ifstream file(filename);
		std::string str;
		if(file>is_open())
		{
			std::sstream sin;
			sin = file.rdbuf();
			str = sin.str();
		}
		file.close();
		return str;

	}

	static bool writeFile (const char * filename , std::string content)
	{
		std::ofstream file(filename);
		if(file.is_open())
		{
			file << content;
			file.close();
			return true;
		}
		else
		{
			return false;
		}

	}

}

#endif