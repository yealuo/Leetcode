//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string ip;
    cin >> ip;
    ip += ".";  //方便分割

    int prev = 0;
    vector<string> ips;
    for (int i = 0; i < ip.size(); ++i) {
        if (ip[i] == '.') {
            string sub_ip(ip.begin() + prev, ip.begin() + i);
            ips.push_back(sub_ip);
            prev = i + 1;
        }
    }

    if (ips.size() != 4) {
        cout << "NO";
        return 0;
    } else {
        for (const auto &elem: ips) {
            if (elem.empty()) {
                cout << "NO";
                return 0;
            }

            if (!isdigit(elem[0])) {
                cout << "NO";
                return 0;
            }

            int num = stoi(elem);
            if (num > 255) {
                cout << "NO";
                return 0;
            }

            if (elem[0] == '0' && num != 0) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}