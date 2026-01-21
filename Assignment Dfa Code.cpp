#include <iostream>
#include <string>
using namespace std;

enum State {
    q0, q1, q2, q3, q4, q5, dead
};

State transition(State current, char input) {
    switch (current) {
        case q0:
            if (input == 'b') return q1;
            return dead;

        case q1:
            if (input == 'a') return q2;
            return dead;

        case q2:
            if (input == 'b') return q1;
            if (input == 'a') return q4;
            return dead;

        case q3:
            if (input == 'b') return q3;
            if (input == 'a') return q4;
            return dead;

        case q4:
            if (input == 'a') return q5;
            if (input == 'b') return q1;
            return dead;

        case q5:
            if (input == 'a') return q5;
            if (input == 'b') return q1;
            return dead;

        default:
            return dead;
    }
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    State current = q0;

    for (char c : input) {
        current = transition(current, c);
        if (current == dead) break;
    }

    if (current == q4 || current == q5)
        cout << "Accepted";
    else
        cout << "Rejected";

    return 0;
}
