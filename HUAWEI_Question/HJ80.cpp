//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n1;
    cin >> n1;
    set<int> nums1;
    for (int i = 0; i < n1; ++i) {
        int temp;
        cin >> temp;
        nums1.insert(temp);
    }

    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int temp;
        cin >> temp;
        nums1.insert(temp);
    }

    for (const auto &n: nums1)
        cout << n;

    return 0;
}