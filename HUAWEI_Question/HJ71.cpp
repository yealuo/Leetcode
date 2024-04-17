//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string pattern, target;
    cin >> pattern >> target;

    vector<vector<bool>> dp(pattern.size() + 1, vector<bool>(target.size() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= pattern.size(); ++i)
        dp[i][0] = dp[i - 1][0] && pattern[i - 1] == '*';   //当目标串为空时，只有模式串全为'*'时才可匹配成功

    for (int i = 1; i <= pattern.size(); ++i) {
        for (int j = 1; j <= target.size(); ++j) {
            if (pattern[i - 1] == '*') {
                if (!isalnum(target[j - 1]))
                    dp[i][j] = dp[i - 1][j];    //当目标为当前位不是字母或数字时，模式串当前位的'*'只能匹配0位
                else
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];    //模式串当前位为'*'，则其可匹配0位或多位
            } else if (pattern[i - 1] == '?') {
                if (!isalnum(target[j - 1]))
                    dp[i][j] = false;   //当目标为当前位不是字母或数字时，'?'无法匹配
                else
                    dp[i][j] = dp[i - 1][j - 1];    //'?'匹配目标串当前位
            } else  //模式串当前位为字母、数字或符号时，只有当前位与目标串相同时才可匹配成功
                dp[i][j] = dp[i - 1][j - 1] && tolower(pattern[i - 1]) == tolower(target[j - 1]);
        }
    }

    cout << (dp[pattern.size()][target.size()] ? "true" : "false");

    return 0;
}