//
// Created by Administrator on 2024/4/10.
//
#include <iostream>

using namespace std;

int main() {
    double base;
    cin >> base;
    double result = base;
    for (int i = 0; i < 4; ++i) {
        result += (base /= 2) * 2;
    }
    cout << result << '\n' << base / 2;

    return 0;
}