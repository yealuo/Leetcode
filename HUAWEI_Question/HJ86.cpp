//
// Created by Administrator on 2024/4/16.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0, max = 0;
    while (n != 0) {
        if ((n & 1) == 1) {
            ++count;
            max = count > max ? count : max;
        } else
            count = 0;

        n >>= 1;
    }

    cout << max;

    return 0;
}