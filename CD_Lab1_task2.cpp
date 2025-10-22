#include <iostream>
using namespace std;

int main() {

    string input;
    cout << "Enter something: ";
    cin >> input;

    int operatorCount = 0;
    int i;
    for (i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') {
            operatorCount++;
            cout << "operator " << operatorCount << ": " << ch << endl;
        }
    }

    return 0;
}
