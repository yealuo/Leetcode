//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double num;
    cin >> num;

    double left = min(-1.0, num), right = max(1.0, num);
    double mid;
    while (right - left > 0.001) {
        mid = (right + left) / 2;
        if (mid * mid * mid > num)
            right = mid;
        else
            left = mid;
    }

    cout << fixed << setprecision(1) << left;

    return 0;
}