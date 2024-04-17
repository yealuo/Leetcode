//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    int type;
    cin >> type;
    if (type == 0)
        sort(nums.begin(), nums.end());
    else
        sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    for (const auto &elem: nums)
        cout << elem << " ";

    return 0;
}