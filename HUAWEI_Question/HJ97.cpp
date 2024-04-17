//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    int neg = 0;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp < 0)
            ++neg;
        else if (temp > 0)
            pos.emplace_back(temp);
    }

    cout << neg << " ";

    double aver = 0.0;
    if (!pos.empty()) {
        for (const auto &i: pos) {
            aver += i;
        }
        aver /= pos.size();
    }

    cout << fixed << setprecision(1) << aver;

    return 0;
}