#ifndef JSON_H
#define JSON_H

#include <map>
#include <vector>
#include <string>
#include <initializer_list>

namespace json
{
	enum jsonType
	{
		jsonString;
		jsonBool;
		jsonNumber;
		jsonList;
		jsonObject;
	};

	class json_Util
	{
	public:	
		static json_Data read (const char * filename);
		static bool write (const char * filename , json_Data val);

	};

	class json_Data
	{
	public:
		static json_Data parse (std::string str);

	protected:

	};
}

#endif