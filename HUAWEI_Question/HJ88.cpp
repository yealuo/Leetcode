//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string in;
    getline(cin, in);

    auto pos = in.find('-');
    string cards1(in.begin(), in.begin() + pos), cards2(in.begin() + pos + 1, in.end());
    stringstream ss1(cards1), ss2(cards2);
    vector<string> c1, c2;
    string temp;
    while (ss1 >> temp)
        c1.push_back(temp);
    while (ss2 >> temp)
        c2.push_back(temp);

    if (c1.size() != c2.size()) {   //两副牌数量不等
        if (c1.size() == 2 && cards1[0] == 'j') //有大小王
            cout << cards1;
        else if (c2.size() == 2 && cards2[0] == 'j')
            cout << cards2;
        else if (c1.size() == 4)    //有炸弹
            cout << cards1;
        else if (c2.size() == 4)
            cout << cards2;
        else
            cout << "ERROR";
    } else {  //两副牌数量相等
        vector<string> priority{"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker"};
        if (find(priority.begin(), priority.end(), c1[0]) > find(priority.begin(), priority.end(), c2[0]))
            cout << cards1;
        else
            cout << cards2;
    }

    return 0;
}