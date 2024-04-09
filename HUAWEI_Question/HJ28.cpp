//
// Created by Administrator on 2024/4/9.
//
#include <iostream>
#include <vector>

using namespace std;

bool is_prime_num(const int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool is_match(int odd, vector<vector<int>> &evens, vector<bool> &used) {
    for (int i = 0; i < evens.size(); ++i) {
        if (is_prime_num(odd + evens[i][0]) && !used[i]) {
            used[i] = true;
            if (evens[i][1] == 0 || is_match(evens[i][1], evens, used)) {
                evens[i][1] = odd;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int count;
    cin >> count;
    vector<int> odds;
    vector<vector<int>> evens;
    while (count--) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) {
            evens.push_back({temp, 0});
        } else {
            odds.push_back(temp);
        }
    }

    int result = 0;
    for (const auto &odd: odds) {
        vector<bool> used(evens.size(), false);
        if (is_match(odd, evens, used)) {
            ++result;
        }
    }
    cout << result;

    return 0;
}