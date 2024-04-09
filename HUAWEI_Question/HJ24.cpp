//
// Created by Administrator on 2024/4/6.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        height.push_back(temp);
    }

    //最长递增子序列
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (height[i] > height[j]) {
                dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
        }
    }

    //最长递减子序列
    vector<int> dp2(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (height[i] > height[j]) {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
    }

    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        max_length = max(dp1[i] + dp2[i] - 1, max_length);
    }

    cout << n - max_length;

    return 0;
}