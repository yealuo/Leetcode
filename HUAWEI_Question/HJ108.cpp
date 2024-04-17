//
// Created by Administrator on 2024/4/17.
//
#include <iostream>

using namespace std;

//辗转相除求最大公约数
int max_common_divisor(int a, int b) {
    if (a > b) //保持a最小
        swap(a, b);

    int d = b % a;
    if (d == 0)
        return a;
    else
        return max_common_divisor(d, a);
}

int main() {
    int a1, a2;
    cin >> a1 >> a2;
    cout << a1 * a2 / max_common_divisor(a1, a2);

    return 0;
}