//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> dp(32, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 32; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int target;
    cin >> target;
    cout << dp[target];

    return 0;
}