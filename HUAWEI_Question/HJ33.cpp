//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    string ip1;
    unsigned int ip2;
    cin >> ip1 >> ip2;

    stringstream ss(ip1);
    string trans, sub_str;
    while (getline(ss, sub_str, '.')) {
        bitset<8> sub_num(stoi(sub_str));
        trans += sub_num.to_string();
    }
    cout << stoul(trans, nullptr, 2) << endl;

    bitset<32> bin_num(ip2);
    string ip2_str = bin_num.to_string();
    string result;
    for (int curt = 0; curt <= 32 - 8; curt += 8) {
        sub_str = ip2_str.substr(curt, 8);
        int num = stoi(sub_str, nullptr, 2);
        result += (to_string(num) + ".");
    }
    result.pop_back();
    cout << result;

    return 0;
}