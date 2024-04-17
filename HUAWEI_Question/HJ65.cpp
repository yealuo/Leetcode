//
// Created by Administrator on 2024/4/13.
//
#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int main1() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() > str2.size()) //str1是较短串
        swap(str1, str2);

    int max_len = 0;
    string max_str;
    for (int i = 0; i < str1.size(); ++i) {
        for (int j = i; j < str1.size(); ++j) {
            string sub_str = str1.substr(i, j - i + 1);
            if (str2.find(sub_str) != string::npos) {
                if (sub_str.size() > max_len) {
                    max_len = sub_str.size();
                    max_str = sub_str;
                }
            }
        }
    }

    cout << max_str;

    return 0;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() > str2.size()) //str1是较短串
        swap(str1, str2);

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int max_len = -1;
    string max_str;
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;

            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
                max_str = str1.substr(i - max_len, max_len);
            }
        }
    }

    cout << max_str;

    return 0;
}