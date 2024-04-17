//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c_num;
    cin >> c_num;
    vector<pair<string, int>> count;
    for (int i = 0; i < c_num; ++i) {
        string candidate;
        cin >> candidate;
        count.emplace_back(candidate, 0);
    }

    int invalid = 0;

    int v_num;
    cin >> v_num;
    for (int i = 0; i < v_num; ++i) {
        string voter;
        cin >> voter;

        bool flag = false;
        for (auto &elem: count) {
            if (elem.first == voter) {
                flag = true;
                ++elem.second;
                break;
            }
        }

        if (!flag)
            ++invalid;
    }

    for (const auto &elem: count) {
        cout << elem.first << " : " << elem.second << endl;
    }

    cout << "Invalid : " << invalid;

    return 0;
}