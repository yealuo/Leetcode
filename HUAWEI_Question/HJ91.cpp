//
// Created by Administrator on 2024/4/16.
//
#include <iostream>

using namespace std;

int fac(int i) {
    if (i == 1)
        return 1;

    return i * fac(i - 1);
}

int main() {
    int m, n;
    cin >> n >> m;

    int i = fac(m + n) / (fac(m) * fac(n));

    cout << i;

    return 0;
}