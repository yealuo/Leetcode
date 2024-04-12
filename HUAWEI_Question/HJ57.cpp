//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    std::reverse(str1.begin(), str1.end());
    std::reverse(str2.begin(), str2.end());

    int carry = 0, size = min(str1.size(), str2.size());
    string result;
    for (int i = 0; i < size; ++i) {
        int temp = str1[i] - '0' + str2[i] - '0' + carry;
        carry = temp / 10;
        temp %= 10;
        result += to_string(temp);
    }


    if (str1.size() > str2.size()) {
        for (int i = str2.size(); i < str1.size(); ++i) {
            int temp = str1[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            result += to_string(temp);
        }
    } else {
        for (int i = str1.size(); i < str2.size(); ++i) {
            int temp = str2[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            result += to_string(temp);
        }
    }

    if (carry != 0)
        result += to_string(carry);

    std::reverse(result.begin(), result.end());
    cout << result;

    return 0;
}