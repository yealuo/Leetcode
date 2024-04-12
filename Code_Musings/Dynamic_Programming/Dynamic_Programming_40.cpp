//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        ++result;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}