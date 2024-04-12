//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <cmath>

using namespace std;

bool is_perfect(int num) {
    int add = 1;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            if (num / i == i)
                add += i;
            else
                add += i + num / i;
        }
    }

    if (num == add)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_perfect(i))
            ++count;
    }

    cout << count;

    return 0;
}