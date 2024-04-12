//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1 || n == 2)
        cout << -1;
    else {
        n = (n - 2) % 4;
        if (n == 0)
            cout << 4;
        else if (n == 1 || n == 3)
            cout << 2;
        else
            cout << 3;
    }

    return 0;
}