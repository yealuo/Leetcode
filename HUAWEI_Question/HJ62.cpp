//
// Created by Administrator on 2024/4/12.
//
#include <iostream>

using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int count = 0;
        while (num != 0) {
            if ((num & 1) == 1)
                ++count;
            num >>= 1;
        }
        cout << count << endl;
    }
    return 0;
}