#include <iostream>
using namespace std;

int main() {

    string input;
    bool isNumeric = true;

    cout << "Enter something: ";
    cin >> input;
    int i;
    for (i = 0; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric)
        cout << "Numeric constant" << endl;
    else
        cout << "Not numeric" << endl;

    return 0;
}
