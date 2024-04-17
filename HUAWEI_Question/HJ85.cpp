//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));

    int max_len = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        for (int j = i; j < str.size(); ++j) {
            if (i == j)
                dp[i][j] = 1;
            else if (j - i == 1)
                dp[i][j] = str[i] == str[j] ? 2 : 0;
            else {
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1] != 0 ? dp[i + 1][j - 1] + 2 : 0;
                } else
                    dp[i][j] = 0;
            }
            max_len = dp[i][j] > max_len ? dp[i][j] : max_len;
        }
    }

    cout << max_len;

    return 0;
}