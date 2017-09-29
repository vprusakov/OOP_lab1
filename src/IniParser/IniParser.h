#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../IniParserException/IniParserException.h"

using namespace std;

class IniParser {
public:
	IniParser() {};
	// Opens Ini file.
	void Initialize(const string& filename);
	// Processing and saving data
	void Parse();
	//Print
	void PrintAll();
	// Checks if a section exists.
	bool IsHaveSection(string& section_name);
	// Checks if a pair param-section exists.
	bool IsHaveParam(const string& section_name,const string& param_name);
	// Returns values.
	template <class T> T GetValue(string& section_name, string& param_name);
	
	std::string GetValueString(const char* section_name, const char* param_name);
private:
	ifstream file;
	map<string, map<string, string> > sections;
};