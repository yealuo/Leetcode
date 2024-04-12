//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i < j)
                dp[i][j] = dp[i][i];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    }

    cout << dp[m][n];

    return 0;
}