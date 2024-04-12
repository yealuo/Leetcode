//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int alpha = 0, space = 0, digit = 0, other = 0;
    string in;
    getline(cin, in);
    for (const auto &elem: in) {
        if (isalpha(elem))
            ++alpha;
        else if (isspace(elem))
            ++space;
        else if (isdigit(elem))
            ++digit;
        else
            ++other;
    }
    cout << alpha << "\n" << space << "\n" << digit << "\n" << other;

    return 0;
}