#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class IniParser {
private:
	ifstream file;
	map<string, map<string, string> > sections;
public:
	IniParser() {};
	// Opens Ini file.
	void Initialize(string filename);
	// Processing and saving data
	void Parse();
	//Print
	void PrintAll();
	// Checks if a section exists.
	bool IsHaveSection(string section_name);
	// Checks if a pair param-section exists.
	bool IsHaveParam(string section_name, string param_name);
	// Returns integer value for a pair param-section.
	int GetValueInt(string section_name, string param_name);
	// Returns double value for a pair param-section.
	double GetValueDouble(const char* section_name, const char* param_name);
	// Return string value for a pair param-section.
	std::string GetValueString(const char* section_name, const char* param_name);

};