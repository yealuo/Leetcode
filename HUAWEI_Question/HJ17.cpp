//
// Created by Administrator on 2024/4/2.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool if_valid(const string &str) {
    if (str.empty()) {
        return false;
    }

    vector<char> dir{'A', 'S', 'D', 'W'};
    vector<char> num{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    if (find(dir.begin(), dir.end(), str[0]) == dir.end()) {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) {
        if (find(num.begin(), num.end(), str[i]) == num.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    int x = 0, y = 0;
    string in;
    cin >> in;
    vector<vector<string>> opers;
    int prev = 0;
    for (int curt = 0; curt < in.size(); ++curt) {
        if (in[curt] == ';') {
            string substr(in.begin() + prev, in.begin() + curt);
            //合法性检测
            if (!if_valid(substr)) {
                prev = curt + 1;
                continue;
            }

            vector<string> temp;
            temp.emplace_back(substr.begin(), substr.begin() + 1);
            temp.emplace_back(substr.begin() + 1, substr.end());
            prev = curt + 1;
            opers.push_back(temp);
        }
    }

    for (const auto &oper: opers) {
        if (oper[0] == "A") {
            x -= stoi(oper[1]);
        } else if (oper[0] == "S") {
            y -= stoi(oper[1]);
        } else if (oper[0] == "D") {
            x += stoi(oper[1]);
        } else if (oper[0] == "W") {
            y += stoi(oper[1]);
        }
    }

    cout << x << ',' << y;

    return 0;
}
// 64 位输出请用 printf("%lld")