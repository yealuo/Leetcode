//
// Created by Administrator on 2024/4/19.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}