#include "IniParser/IniParser.h"

int main() {
    IniParser p("../input_files/lab01_input_correct_09.ini");
	try {
		//p.PrintAll();
        p.IsHaveSection("DEMODS");
        p.IsHaveParam("SECTION2", "RawIQType");
		//cout << p.GetValue<int>("COMMON", "asdf") << endl;
	}
	catch (IniParserException& e) {
		cerr << e.what();
	}
    return 0;
}