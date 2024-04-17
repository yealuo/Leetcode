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
        {1, "Ҽ"},
        {2, "��"},
        {3, "��"},
        {4, "��"},
        {5, "��"},
        {6, "½"},
        {7, "��"},
        {8, "��"},
        {9, "��"}
};

unordered_map<int, string> dict2{
        {0, ""},
        {1, "ʰ"},
        {2, "��"},
        {3, "Ǫ"}
};

unordered_map<int, string> dict3{
        {0, "Ԫ"},
        {1, "��"},
        {2, "��"}
};

int main() {
    string result;

    string in;
    cin >> in;

    string integer(in.begin(), in.begin() + in.find('.'));
    string decimal(in.begin() + in.find('.') + 1, in.end());

    //С������
    if (decimal[0] != '0')
        result += dict[decimal[0] - '0'] + "��";
    if (decimal[1] != '0')
        result += dict[decimal[1] - '0'] + "��";
    if (decimal[0] == '0' && decimal[1] == '0')
        result += "��";

    //��������
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
                    sub_result = "��" + sub_result;
                }
            } else {
                if (j == 1 && n[i][j] == '1')    //ʮλΪ1ʱ���⴦��
                    sub_result = dict2[j] + sub_result;
                else
                    sub_result = dict[n[i][j] - '0'] + dict2[j] + sub_result;
            }
        }
        result = sub_result + dict3[i] + result;
    }

    cout << "�����" << result;

    return 0;
}