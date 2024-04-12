//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cin >> num;

    for (int i = num / 2; i > 0; --i) {
        if (is_prime(i) && is_prime(num - i)) {
            cout << i << "\n" << num - i;
            break;
        }
    }

    return 0;
}