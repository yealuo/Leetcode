//
// Created by Administrator on 2024/4/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> dp(cost.size());
        dp[dp.size() - 1] = cost[dp.size() - 1];
        dp[dp.size() - 2] = cost[dp.size() - 2];
        for (int i = dp.size() - 3; i >= 0; --i) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};

int main() {
    return 0;
}