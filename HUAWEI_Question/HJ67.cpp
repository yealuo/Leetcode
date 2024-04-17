//
// Created by Administrator on 2024/4/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<int> &num, double result) {
    if (num.empty()) {
        if (result == 24)
            return true;
        else
            return false;
    }

    for (int i = 0; i < num.size(); ++i) {
        vector<int> copy(num);
        int curt = copy[i];
        copy.erase(copy.begin() + i);

        if (dfs(copy, result + curt) || dfs(copy, result - curt) || dfs(copy, result * curt) ||
            dfs(copy, result / curt))
            return true;
    }

    return false;
}

int main() {
    vector<int> in(4);
    for (int i = 0; i < 4; ++i) {
        cin >> in[i];
    }

    if (dfs(in, 0))
        cout << "true";
    else
        cout << "false";

    return 0;
}