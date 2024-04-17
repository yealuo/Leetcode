//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    getline(cin, in);

    int count = 0;
    for (const auto &elem: in) {
        if (isupper(elem))
            ++count;
    }

    cout << count;

    return 0;
}