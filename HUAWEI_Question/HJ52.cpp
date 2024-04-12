//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str_a, str_b;
    while (cin >> str_a >> str_b) {
        vector<vector<int>> dp(str_a.size() + 1, vector<int>(str_b.size() + 1));
        for (int i = 0; i < str_a.size() + 1; ++i)
            dp[i][0] = i;
        for (int i = 0; i < str_b.size() + 1; ++i)
            dp[0][i] = i;

        for (int i = 1; i < str_a.size() + 1; ++i) {
            for (int j = 1; j < str_b.size() + 1; ++j) {
                if (str_a[i - 1] == str_b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    //这里的意思是min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);但min只接受两个参数，所以里面再用一个min()
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }

        cout << dp[str_a.size()][str_b.size()] << endl;
    }

    return 0;
}