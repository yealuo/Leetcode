//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    cin >> in;

    vector<char> c;
    vector<bool> flag(256, true);
    for (const auto &elem: in) {
        if (flag[elem]) {
            c.push_back(elem);
        } else {
            auto it = find(c.begin(), c.end(), elem);
            if (it != c.end())
                c.erase(it);
        }

        flag[elem] = false;
    }

    if (!c.empty())
        cout << c[0];
    else
        cout << -1;

    return 0;
}