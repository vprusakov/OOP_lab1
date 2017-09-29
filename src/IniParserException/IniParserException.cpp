#include "IniParserException.h"

const char* IniParserException::what() const {
	return message.c_str();
}