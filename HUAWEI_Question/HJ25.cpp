//
// Created by Administrator on 2024/4/6.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<int> I;
    for (int i = 0; i < count; ++i) {
        int temp;
        cin >> temp;
        I.push_back(temp);
    }
    cin >> count;
    set<int> R;
    for (int i = 0; i < count; ++i) {
        int temp;
        cin >> temp;
        R.insert(temp);
    }

    map<int, vector<pair<int, int>>> result;

    count = 0;
    for (int i = 0; i < I.size(); ++i) {
        for (const auto &r: R) {
            if (to_string(I[i]).find(to_string(r)) != string::npos) {
                result[r].emplace_back(i, I[i]);
                ++count;
            }
        }
    }

    size_t all_num = result.size() * 2 + count * 2;
    cout << all_num;
    for (const auto &elem: result) {
        cout << " " << elem.first << " " << elem.second.size();
        for (const auto &num: elem.second) {
            cout << " " << num.first << " " << num.second;
        }
    }

    return 0;
}