#include "IniParser/IniParser.h"

int main() {
    IniParser p;
	try {
		p.Initialize("../input_files/lab01_input_correct_091.ini");
		cout << p.GetValue("DEMODS", "BufferLenSeconds") << endl;
	}
	catch (IniParserException e) {
		cerr << e.what();
	}
	system("pause");
    return 0;
}