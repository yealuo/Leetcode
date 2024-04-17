//
// Created by Administrator on 2024/4/17.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int delta = 3, last = 2 + delta * (n - 1);

    cout << (2 + last) * n / 2;

    return 0;
}