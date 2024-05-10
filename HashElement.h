#ifndef __HASH_ELEMENT_H__
#define __HASH_ELEMENT_H__

#include <string>
#include <sstream>

class HashElement
{
public:
	int key;
	std::string value;

	HashElement(int key, const std::string& value)
		: key(key)
		, value(value)
	{
	}

	std::string ToString() const
	{
		std::ostringstream oss;
		oss << key << ": " << value;
		return oss.str();
	}
};

#endif