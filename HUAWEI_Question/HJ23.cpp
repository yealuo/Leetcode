//
// Created by Administrator on 2024/4/3.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int main() {
    string in;
    cin >> in;
    unordered_map<char, int> least;
    for (const auto &alpha: in) {
        ++least[alpha];
    }

    int min = INT_MAX;
    vector<char> target;

    for (const auto i: least) {
        if (i.second < min) {
            target.clear();
            target.push_back(i.first);
            min = i.second;
        } else if (i.second == min) {
            target.push_back(i.first);
        }
    }

    for (const auto alpha: target) {
        for (int i = 0; i < in.size(); ++i) {
            if (in[i] == alpha)
                in.erase(i, 1);
        }
    }

    cout << in;

    return 0;
}