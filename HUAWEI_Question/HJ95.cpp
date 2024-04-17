//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<int, string> dict{
        {0, ""},
        {1, "壹"},
        {2, "贰"},
        {3, "叁"},
        {4, "肆"},
        {5, "伍"},
        {6, "陆"},
        {7, "柒"},
        {8, "捌"},
        {9, "玖"}
};

unordered_map<int, string> dict2{
        {0, ""},
        {1, "拾"},
        {2, "佰"},
        {3, "仟"}
};

unordered_map<int, string> dict3{
        {0, "元"},
        {1, "万"},
        {2, "亿"}
};

int main() {
    string result;

    string in;
    cin >> in;

    string integer(in.begin(), in.begin() + in.find('.'));
    string decimal(in.begin() + in.find('.') + 1, in.end());

    //小数部分
    if (decimal[0] != '0')
        result += dict[decimal[0] - '0'] + "角";
    if (decimal[1] != '0')
        result += dict[decimal[1] - '0'] + "分";
    if (decimal[0] == '0' && decimal[1] == '0')
        result += "整";

    //整数部分
    reverse(integer.begin(), integer.end());
    int prev = 0;
    vector<string> n;
    for (int i = 4; i < integer.size(); i += 4) {
        n.emplace_back(integer.begin() + prev, integer.begin() + i);
        prev = i;
    }
    n.emplace_back(integer.begin() + prev, integer.end());

    for (int i = 0; i < n.size(); ++i) {
        if (n[i] == "0" || n[i] == "0000")
            continue;

        string sub_result;
        bool flag = false;
        for (int j = 0; j < n[i].size(); ++j) {
            if (n[i][j] == '0') {
                if (!sub_result.empty() && !flag) {
                    flag = true;
                    sub_result = "零" + sub_result;
                }
            } else {
                if (j == 1 && n[i][j] == '1')    //十位为1时特殊处理
                    sub_result = dict2[j] + sub_result;
                else
                    sub_result = dict[n[i][j] - '0'] + dict2[j] + sub_result;
            }
        }
        result = sub_result + dict3[i] + result;
    }

    cout << "人民币" << result;

    return 0;
}