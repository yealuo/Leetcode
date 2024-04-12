//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> in(n);
    for (int i = 0; i < n; ++i)
        cin >> in[i];

    std::sort(in.begin(), in.end());
    for (int i = 0; i < k; ++i)
        cout << in[i] << " ";

    return 0;
}