#include "StringHelper.hpp"

std::wstring StringHelper::StringToWide(std::string str)
{
	return std::wstring(str.begin(),str.end());
}
