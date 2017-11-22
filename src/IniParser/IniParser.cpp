#include "IniParser.h"
#include "../IniParserException/IniParserException.h"

IniParser::IniParser(const string& filename) throw(Exc_IO) {
    Initialize(filename);
    if (!file.is_open() || !file.good()) {
        throw Exc_IO(filename);
    }
    Parse();
}
void IniParser::Initialize(const string& filename) throw(Exc_IO) {
    file.open(filename);
    if (!file.is_open() || !file.good()) {
        throw Exc_IO(filename);
    }
}
void IniParser::Parse() throw(Exc_IncorrectFormat) {
    std::string s;
    std::string section_name, param_key, param_value;
    size_t len, foundSemiColon, foundDelim;
    while (std::getline(file, s)) {
        foundSemiColon = s.find(';');
        if (foundSemiColon != std::string::npos) {
            s = s.substr(0, foundSemiColon);
        }
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        if (!s.empty()) {
            len = s.length();
            if (s[0]=='[' && s[s.length()-1]==']') {
                section_name = s.substr(1, len-2);
            }
            else {
                foundDelim = s.find('=');
                if (foundDelim != std::string::npos) {
                    param_key = s.substr(0, foundDelim);
                    param_value = s.substr(foundDelim+1, len-foundDelim);
                }
                else throw Exc_IncorrectFormat(s);
                data[section_name].insert(make_pair(param_key, param_value));
            }
        }
    }
}
void IniParser::PrintAll() {
	map<string, map<string, string> >::iterator it;
	map<string, string>::iterator init;
	for (it = data.begin(); it != data.end(); it++) {
		cout << "_"<< it->first << "_"<< endl;
		for (init = (it->second).begin(); init != (it->second).end(); init++) {
			cout << "_"<< init->first << "_"<< init->second << "_"<< endl;
		}
	}
};
bool IniParser::IsHaveSection(const string& section_name) const throw() {
	if (data.find(section_name) != data.end()) return true;
	return false;
};
bool IniParser::IsHaveParam(const string& section_name, const string& param_name) const throw(Exc_SectionNotFound, Exc_ParamNotFound) {
	if (IsHaveSection(section_name)) {
		if (data.at(section_name).find(param_name) == data.at(section_name).end())
			throw Exc_ParamNotFound(param_name);
	}
	else throw Exc_SectionNotFound(section_name);
	return true;
};
template<>
int IniParser::GetValue<int>(const string &section_name, const string &param_name) const {
	IsHaveParam(section_name, param_name);

        stoi(data.find(section_name)->second.find(param_name)->second);

    }
}
template<>
double IniParser::GetValue<double>(const string &section_name, const string &param_name) const {
	IsHaveParam(section_name, param_name);
	return stod(data.find(section_name)->second.find(param_name)->second);
}
template<>
std::string IniParser::GetValue<std::string>(const string &section_name, const string &param_name) const {
	IsHaveParam(section_name, param_name);
	return data.find(section_name)->second.find(param_name)->second;
}


