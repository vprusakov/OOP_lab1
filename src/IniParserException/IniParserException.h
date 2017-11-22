#pragma once

#include <exception>
#include <string>

class IniParserException : public std::exception {
public:
    IniParserException(const std::string &excMessage) : message(excMessage) {}
	std::string  what() {
        return message;
    }
    ~IniParserException() throw() {}
private:
    std::string message;
};
class Exc_IO : public IniParserException {
public:
	Exc_IO(const std::string &filename) : IniParserException("File " + filename + " can't be read.\n") {};
};
class Exc_IncorrectFormat : public IniParserException {
public:
    Exc_IncorrectFormat(const std::string &line) : IniParserException("Format incorrect in line: " + line) {};
};
class Exc_SectionNotFound : public IniParserException {
public:
	Exc_SectionNotFound(const std::string &section_name) : IniParserException("Section '" + section_name + "' is not found.\n") {};
};
class Exc_ParamNotFound : public IniParserException {
public:
	Exc_ParamNotFound(const std::string &param_name) : IniParserException("Param '" + param_name + "' is not found.\n") {};
};