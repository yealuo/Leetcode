//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int type_count;
    cin >> type_count;
    vector<int> weight(type_count);
    vector<int> amount(type_count);
    for (int i = 0; i < type_count; ++i)
        cin >> weight[i];
    for (int i = 0; i < type_count; ++i)
        cin >> amount[i];

    int total_weight = 0;
    for (int i = 0; i < type_count; ++i)
        total_weight += weight[i] * amount[i];

    vector<int> Weight;
    Weight.emplace_back(0);
    for (int i = 0; i < weight.size(); ++i) {
        for (int j = 0; j < amount[i]; ++j)
            Weight.emplace_back(weight[i]);
    }

    vector<vector<bool>> dp(Weight.size(), vector<bool>(total_weight + 1, false));
    unordered_set<int> result;
    for (int i = 0; i < Weight.size(); ++i)
        dp[i][0] = true;

    for (int i = 1; i < Weight.size(); ++i) {
        for (int j = 1; j < total_weight + 1; ++j) {
            if (j < Weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - Weight[i]];

            if (dp[i][j])
                result.insert(j);
        }
    }

    cout << result.size() + 1;  //重量0也算

    return 0;
}