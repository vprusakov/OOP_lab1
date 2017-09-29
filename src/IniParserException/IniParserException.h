#pragma once

#include <exception>

class IniParserException : public std::exception {
public:
    IniParserException(const string &exception_name) : message(exception_name) {}
    const char* what() const throw()  {};
    ~IniParserException() {}
private:
    string message;
};