//
// Created by Administrator on 2024/4/15.
//
#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    bool flag;
    while (cin >> str1 >> str2) {
        flag = true;
        for (const auto &alpha: str1) {
            if (str2.find(alpha) == string::npos) {
                cout << "false" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "true" << endl;
    }

    return 0;
}