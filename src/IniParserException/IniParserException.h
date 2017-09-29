#pragma once

#include <exception>
#include <string>

class IniParserException : public std::exception {
public:
    IniParserException(const std::string &exception) : message(exception) {}
	const char* what() const override;
    ~IniParserException() {}
private:
    std::string message;
};