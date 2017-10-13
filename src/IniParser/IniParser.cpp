#include "IniParser.h"
#include "../IniParserException/IniParserException.h"

void IniParser::Initialize(const string& filename) {
	file.open(filename);
	if (!file.is_open() || !file.good()) {
		throw IniParserException("Error while opening " + filename + "\n");
	}
	Parse();
};
void IniParser::Parse() {
	string s, section_name, param_key, param_value;

	while (true) {
		if (s[0] == '[') {
			section_name = s.substr(1, s.length() - 2);
		}
		else if (s[0] != ';' && s[0] != '\0') {
			param_key = s.substr(0, s.find('='));
			if (param_key.find(' ')) {
				param_key = param_key.substr(0, param_key.find_first_of(' '));
			}
			param_value = s.substr(s.find('=') + 1);
			param_value = param_value.substr(param_value.find_first_not_of(' '));
			if (param_value.find(';')) {
				param_value = param_value.substr(0, param_value.find(';'));
			}
			if (param_value.find(' ')) {
				param_value = param_value.substr(0, param_value.find_first_of(' '));
			}
			data[section_name].insert(make_pair(param_key, param_value));
		}
		if (!file.eof()) {
			getline(file, s);
		}
		else break;
	}
}
void IniParser::PrintAll() {
	map<string, map<string, string> >::iterator it;
	map<string, string>::iterator init;
	for (it = data.begin(); it != data.end(); it++) {
		cout << it->first << endl;
		for (init = (it->second).begin(); init != (it->second).end(); init++) {
			cout << init->first << init->second << endl;
		}
	}
};
bool IniParser::IsHaveSection(const string& section_name) {
	if (data.find(section_name) != data.end()) return true;
	else throw IniParserException("Section '" + section_name + "' is not found.\n");
	return false;
};
bool IniParser::IsHaveParam(const string& section_name,const string& param_name) {
	if (IsHaveSection(section_name)) {
		if (data[section_name].find(param_name) != data[section_name].end()) return true;
		else throw IniParserException("Param '" + param_name + "' is not found.\n");
	}
	return false;
};
int IniParser::GetValueInt(const string& section_name, const string& param_name) {
	string value = data.find(section_name)->second.find(param_name)->second;
	int result;

	if (IsHaveParam(section_name, param_name)) {
		try {
			result = stoi(value);
		}
		catch (const invalid_argument &e) {
			throw IniParserException("Error while converting int value of " + param_name);
		}
	}
	return result;
};
double IniParser::GetValueDouble(const string& section_name, const string& param_name) {
	string value = data.find(section_name)->second.find(param_name)->second;
	int result;

	if (IsHaveParam(section_name, param_name)) {
		try {
			result = stod(value);
		}
		catch (const invalid_argument &e) {
			throw IniParserException("Error while converting double value of " + param_name);
		}
	}
	return result;
};
string IniParser::GetValueString(const string& section_name, const string& param_name) {
	return data.find(section_name)->second.find(param_name)->second;
};
