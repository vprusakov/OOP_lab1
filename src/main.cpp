#include "IniParser/IniParser.h"

int main() {
    IniParser p;
	try {
		p.Initialize("../input_files/lab01_input_correct_111.ini");
		p.Parse();
		cout << p.IsHaveParam("DEBUG", "CheckThisParameter") << " ";
		p.PrintAll();
	}
	catch (IniParserException e) {
		cerr << e.what();
	}
	system("pause");
    return 0;
}