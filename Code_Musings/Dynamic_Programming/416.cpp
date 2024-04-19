//
// Created by Administrator on 2024/4/19.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                }
            }
        }

        return dp[nums.size()][sum] == sum;
    }
};

int main() {
    return 0;
}