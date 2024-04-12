//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int count;
    cin >> str >> count;

    for (int i = 0; i < count; ++i)
        cout << str[i];

    return 0;
}