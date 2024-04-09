//
// Created by Administrator on 2024/4/9.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    for (auto &elem: a) {
        if (isalpha(elem)) {
            if (isupper(elem))
                elem = tolower(elem == 'Z' ? 'A' : elem + 1);
            else
                elem = toupper(elem == 'z' ? 'a' : elem + 1);
        } else if (isdigit(elem))
            elem = elem == '9' ? '0' : elem + 1;
    }
    cout << a << endl;

    for (auto &elem: b) {
        if (isalpha(elem)) {
            if (isupper(elem))
                elem = tolower(elem == 'A' ? 'Z' : elem - 1);
            else
                elem = toupper(elem == 'a' ? 'z' : elem - 1);
        } else if (isdigit(elem))
            elem = elem == '0' ? '9' : elem - 1;
    }
    cout << b;

    return 0;
}