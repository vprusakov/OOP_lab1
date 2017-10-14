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
	void Parse() const;
	//Print
	void PrintAll();
	// Checks if a section exists.
	bool IsHaveSection(const string& section_name);
	// Checks if a pair param-section exists.
	bool IsHaveParam(const string& section_name,const string& param_name);
	// Returns integer value for a pair param-section.
	int GetValueInt(const string& section_name, const string& param_name);
	// Returns double value for a pair param-section.
	double GetValueDouble(const string& section_name, const string& param_name);
	// Return string value for a pair param-section.
	std::string GetValueString(const string& section_name, const string& param_name);
private:
	ifstream file;
	map<string, map<string, string> > data;
};