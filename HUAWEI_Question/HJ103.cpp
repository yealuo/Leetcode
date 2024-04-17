//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<int> &p, int begin) {
    int max = 0;
    for (int i = begin + 1; i < p.size(); ++i) {
        if (p[i] > p[begin]) {
            int n = dfs(p, i);
            max = max > n ? max : n;
        }
    }

    return max + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> pillars(n);
    for (int i = 0; i < n; ++i)
        cin >> pillars[i];

    int max = 0;
    for (int i = 0; i < pillars.size(); ++i) {
        int temp = dfs(pillars, i);
        max = max > temp ? max : temp;
    }

    cout << max;

    return 0;
}