#include "header.h"
#include "IniParserException.h"

void IniParser::Initialize(string filename) {
	file.open(filename);
    if (!file.is_open() || !file.good()) throw ExceptionIO("file error");
};


void IniParser::Parse() {

	string s;
	string section_name, param_key, param_value;

	while (true) {
		if (s[0] == '[') {
			section_name = s.substr(1, s.length() - 2);
		}
		else if (s[0] != ';' && s[0] != '\0') {
			param_key = s.substr(0, s.find('='));
			if (param_key.find(' ')) param_key = param_key.substr(0, param_key.find_first_of(' '));
			param_value = s.substr(s.find('=') + 1);
			param_value = param_value.substr(param_value.find_first_not_of(' '));
			if (param_value.find(';')) param_value = param_value.substr(0, param_value.find(';'));
			if (param_value.find(' ')) param_value = param_value.substr(0, param_value.find_first_of(' '));
			sections[section_name].insert(make_pair(param_key, param_value));
		}
		if (!file.eof()) getline(file, s);
		else break;
	}
}
void IniParser::PrintAll() {
	std::map<string, map<string, string> >::iterator it;
	std::map<string, string>::iterator init;
	for (it = sections.begin(); it != sections.end(); it++) {
		cout << it->first << endl;
		for (init = (it->second).begin(); init != (it->second).end(); init++) {
			cout << "_" << init->first << '_' << init->second << '_' << endl;
		}
	}
};
bool IniParser::IsHaveSection(string section_name) {
	if (sections.find(section_name) != sections.end()) return true;
	return false;
};
bool IniParser::IsHaveParam(string section_name, string param_name) {
	if (sections[section_name].find(param_name) != sections[section_name].end()) return true;
	return false;
};