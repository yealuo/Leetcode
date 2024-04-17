//
// Created by Administrator on 2024/4/14.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num, mode;
    cin >> num >> mode;

    vector<pair<string, int>> grades;
    for (int i = 0; i < num; ++i) {
        string name;
        int grade;
        cin >> name >> grade;
        grades.emplace_back(name, grade);
    }

    if (mode == 0)
        stable_sort(grades.begin(), grades.end(),
                    [](const pair<string, int> &g1, const pair<string, int> &g2) { return g1.second > g2.second; });
    else
        stable_sort(grades.begin(), grades.end(),
                    [](const pair<string, int> &g1, const pair<string, int> &g2) { return g1.second < g2.second; });

    for (const auto &elem: grades)
        cout << elem.first << " " << elem.second << endl;

    return 0;
}