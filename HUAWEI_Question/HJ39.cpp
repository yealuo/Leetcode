//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>

using namespace std;

bool is_mask_valid(const vector<int> &mask) {
    if (mask.size() != 4)
        return false;

    for (const auto &elem: mask) {
        if (!(elem >= 0 && elem <= 255))
            return false;
    }

    stringstream ss;
    for (const auto &elem: mask) {
        ss << bitset<8>(elem);
    }

    string mask_str = ss.str();
    bool flag = false;
    for (const auto &num: mask_str) {
        if (num == '0')
            flag = true;
        if (flag && num == '1')
            return false;
    }
    return true;
}

bool is_ip_valid(const vector<int> &ip) {
    if (ip.size() != 4)
        return false;
    
    for (const auto &elem: ip) {
        if (!(elem >= 0 && elem <= 255))
            return false;
    }
    return true;
}


int main() {
    vector<int> mask, ip1, ip2;
    unsigned int mask_num, ip1_num, ip2_num;
    int a, b, c, d;
    //Mask
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    mask.push_back(a);
    mask.push_back(b);
    mask.push_back(c);
    mask.push_back(d);
    mask_num = (a << 24) + (b << 16) + (c << 8) + d;
    //ip1
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ip1.push_back(a);
    ip1.push_back(b);
    ip1.push_back(c);
    ip1.push_back(d);
    ip1_num = (a << 24) + (b << 16) + (c << 8) + d;
    //ip2
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ip2.push_back(a);
    ip2.push_back(b);
    ip2.push_back(c);
    ip2.push_back(d);
    ip2_num = (a << 24) + (b << 16) + (c << 8) + d;

    if (!is_mask_valid(mask) || !is_ip_valid(ip1) || !is_ip_valid(ip2))
        cout << 1;
    else {
        if ((mask_num & ip1_num) == (mask_num & ip2_num))
            cout << 0;
        else
            cout << 2;
    }

    return 0;
}