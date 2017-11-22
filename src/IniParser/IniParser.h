#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include "../IniParserException/IniParserException.h"

using namespace std;

class IniParser {
public:
    //Opens Ini file
	IniParser(const string& filename) throw(Exc_IO);
	void Initialize(const string& filename) throw(Exc_IO);
	// Processing and saving data
	void Parse() throw(Exc_IncorrectFormat);
	//Print
	void PrintAll() throw();
	// Checks if a section exists.
	bool IsHaveSection(const string& section_name) const throw();
	// Checks if a pair param-section exists.
	bool IsHaveParam(const string& section_name,const string& param_name) const
		throw(Exc_SectionNotFound, Exc_ParamNotFound);
	template<typename T>
	T GetValue(const std::string &section_name, const std::string &param_name) const ;
    ~IniParser() {
        data.clear();
        file.close();
    }
private:
	ifstream file;
	map<string, map<string, string> > data;
};