//
// Created by Administrator on 2024/4/9.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string result(str1 + str2);

    string odds, evens;
    for (int i = 0; i < result.size(); ++i) {
        if (i % 2 != 0)
            odds += result[i];
        else
            evens += result[i];
    }
    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());
    for (int i = 0; i < result.size(); ++i) {
        if (i % 2 != 0)
            result[i] = odds[(i - 1) / 2];
        if (i % 2 == 0)
            result[i] = evens[i / 2];
    }

    for (auto &elem: result) {
        if (isdigit(elem) || (elem >= 'a' && elem <= 'f') || (elem >= 'A' && elem <= 'F')) {
            int num = stoi(string(1, elem), nullptr, 16);
            bitset<4> bin(num);
            string bin_str = bin.to_string();
            std::reverse(bin_str.begin(), bin_str.end());
            num = stoi(bin_str, nullptr, 2);
            stringstream ss;
            ss << hex << uppercase << num;
            elem = ss.str()[0];
        }
    }
    cout << result;

    return 0;
}