#include "header.h"

int main() {
    IniParser p;
    p.Initialize("input_files/lab01_input_correct_09.ini");
    p.Parse();
    cout << p.IsHaveParam("DEBUG", "CheckThisParameter");
    //cout << p.IsHaveParam("COMMON", "LogNCMD") << endl;
    system("pause");
    return 0;
}
