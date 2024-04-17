//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> dict1{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> dict2{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    int days = 0;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {  //闰年
        for (int i = 1; i < month; ++i)
            days += dict2[i];
        cout << days + day;
    } else {    //平年
        for (int i = 1; i < month; ++i)
            days += dict1[i];
        cout << days + day;
    }

    return 0;
}