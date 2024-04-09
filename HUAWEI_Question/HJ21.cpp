//
// Created by Administrator on 2024/4/3.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;
    cin >> password;

    for (auto &mem: password) {
        if (mem == 'a' || mem == 'b' || mem == 'c')
            mem = '2';
        else if (mem == 'd' || mem == 'e' || mem == 'f')
            mem = '3';
        else if (mem == 'g' || mem == 'h' || mem == 'i')
            mem = '4';
        else if (mem == 'j' || mem == 'k' || mem == 'l')
            mem = '5';
        else if (mem == 'm' || mem == 'n' || mem == 'o')
            mem = '6';
        else if (mem == 'p' || mem == 'q' || mem == 'r' || mem == 's')
            mem = '7';
        else if (mem == 't' || mem == 'u' || mem == 'v')
            mem = '8';
        else if (mem == 'w' || mem == 'x' || mem == 'y' || mem == 'z')
            mem = '9';
        else if (isupper(mem)) {
            if (mem == 'Z')
                mem = 'a';
            else
                mem = tolower(mem) + 1;
        }
    }

    cout << password;

    return 0;
}