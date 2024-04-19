//
// Created by Administrator on 2024/4/19.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            int max = 0;
            for (int j = 1; j < i - 1; ++j) {
                int mul1 = j * dp[i - j];
                int mul2 = j * (i - j);
                max = max > mul1 ? max : mul1;
                max = max > mul2 ? max : mul2;
            }
            dp[i] = max;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    s.integerBreak(10);
    return 0;
}