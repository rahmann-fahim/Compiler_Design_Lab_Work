#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    bool inMultiLineComment = false;

    cout << "Enter lines :" << endl;
    while (true) {
        getline(cin, line);
        if (line == "END") break;


        if (inMultiLineComment) {
            cout << "This is inside a multi-line comment." << endl;

            if (line.find("*/") != string::npos) {
                inMultiLineComment = false;
            }
            continue;
        }
        if (line.find("//") != string::npos) {
            cout << "This is a single line comment." << endl;
        }

        else if (line.find("/*") != string::npos) {
            cout << "This is the start of a multi-line comment." << endl;

            if (line.find("*/") == string::npos) {
                inMultiLineComment = true;
            }
        }
        else {
            cout << "This is NOT a comment line." << endl;
        }
    }
    return 0;
}
