//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    string in;
    cin >> in;

    vector<vector<bool>> dp(in.size(), vector<bool>(in.size(), false));
    for (int i = in.size() - 1; i >= 0; --i) {
        for (int j = i; j < in.size(); ++j) {
            if (in[i] == in[j]) {
                if (j - i <= 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }

    for (int column = in.size() - 1; column >= 0; --column) {
        for (int line = 0; line <= in.size() - 1 - column; ++line) {
            if (dp[line][column + line]) {
                cout << column + 1;
                return 0;
            }
        }
    }

    return 0;
}