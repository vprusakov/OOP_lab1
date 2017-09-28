#include "header.h"

int main() {
    IniParser p;
	cout << "hello" << endl;
    p.Initialize("input_files/lab01_input_correct_09.ini");
    p.Parse();
    cout << p.IsHaveParam("DEBUG", "CheckThisParameter") << " ";
	p.PrintAll();

    //cout << p.IsHaveParam("COMMON", "LogNCMD") << endl;
    system("pause");
    return 0;
}
