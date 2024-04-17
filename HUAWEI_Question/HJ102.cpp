//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    cin >> in;
    vector<pair<char, int>> count;
    for (const auto &a: in) {
        int flag = false;
        for (auto &elem: count) {
            if (elem.first == a) {
                ++elem.second;
                flag = true;
                break;
            }
        }

        if (!flag) {
            count.emplace_back(a, 0);
        }
    }

    sort(count.begin(), count.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    });

    for (const auto &elem: count)
        cout << elem.first;

    return 0;
}