//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int node_num;
    cin >> node_num;

    list<int> l;
    int head_value;
    cin >> head_value;
    l.push_front(head_value);

    for (int i = 0; i < node_num - 1; ++i) {
        int value, pos_value;
        cin >> value >> pos_value;
        auto it = find(l.begin(), l.end(), pos_value);
        l.insert(next(it, 1), value);
    }

    int target_value;
    cin >> target_value;

    auto it = find(l.begin(), l.end(), target_value);
    l.erase(it);

    for (const auto &elem: l)
        cout << elem << " ";

    return 0;
}