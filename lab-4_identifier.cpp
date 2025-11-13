#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

bool isKeyword(char word[]) {
    const char* keywords[] = {
        "int", "float", "if", "else", "while", "for", "return", "char", "double", "void"
    };
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isNumber(char word[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isdigit(word[i]))
            return false;
    }
    return (word[0] != '\0');
}

bool isIdentifier(char word[]) {
    if (!isalpha(word[0]) && word[0] != '_')
        return false;
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_')
            return false;
    }
    return true;
}

bool isOperator(const char* word) {
    const char* ops[] = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "!="};
    for (int i = 0; i < 11; i++) {
        if (strcmp(word, ops[i]) == 0)
            return true;
    }
    return false;
}

bool isSymbol(const char* word) {
    const char symbols[] = ";,(){}[]";
    for (int i = 0; symbols[i] != '\0'; i++) {
        if (word[0] == symbols[i] && word[1] == '\0')
            return true;
    }
    return false;
}

int main() {
    ifstream file("token.txt");
    if (!file.is_open()) {
        cout << "Could not open token.txt file!" << endl;
        return 1;
    }

    cout << "Token\t\tType" << endl;
    cout << "------------------" << endl;

    char line[500];

    while (file.getline(line, 500)) {
        int len = strlen(line);
        char word[100];
        int w = 0;

        for (int i = 0; i <= len; i++) {
            char c = line[i];


            if (isspace(c) || c == '\0' || c == ';' || c == ',' || c == '(' || c == ')' ||
                c == '{' || c == '}' || c == '[' || c == ']' || c == '+' || c == '-' ||
                c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '!') {

                if (w > 0) {
                    word[w] = '\0';

                    if (isKeyword(word))
                        cout << word << "\t\tKeyword" << endl;
                    else if (isNumber(word))
                        cout << word << "\t\tNumber" << endl;
                    else if (isIdentifier(word))
                        cout << word << "\t\tIdentifier" << endl;
                    else
                        cout << word << "\t\tUnknown" << endl;

                    w = 0;
                }


                if (c == ';' || c == ',' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
                    char temp[2] = {c, '\0'};
                    cout << temp << "\t\tSymbol" << endl;
                }
                else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '!') {

                    char temp[3] = {c, '\0', '\0'};
                    if ((c == '=' || c == '<' || c == '>' || c == '!') && line[i + 1] == '=') {
                        temp[1] = '=';
                        i++;
                    }
                    cout << temp << "\t\tOperator" << endl;
                }
            }
            else {
                word[w++] = c;
            }
        }
    }

    file.close();
    return 0;
}
