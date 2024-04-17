//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    std::reverse(in.begin(), in.end());
    cout << in;

    return 0;
}