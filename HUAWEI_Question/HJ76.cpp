//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    string result;
    int first = pow(n, 2) - n + 1;
    for (int i = 0; i < n; ++i)
        result += to_string(first + i * 2) + "+";

    result.erase(result.end() - 1);
    cout << result;

    return 0;
}