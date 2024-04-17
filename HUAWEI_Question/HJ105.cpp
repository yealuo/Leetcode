//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int c1 = 0, temp, add = 0, c2 = 0;
    while (cin >> temp) {
        if (temp < 0)
            ++c1;
        else {
            add += temp;
            ++c2;
        }
    }

    double aver;
    if (c2 != 0)
        aver = 1.0 * add / c2;
    else
        aver = 0.0;

    cout << c1 << endl << fixed << setprecision(1) << aver;

    return 0;
}