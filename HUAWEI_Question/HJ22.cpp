//
// Created by Administrator on 2024/4/3.
//
#include <iostream>

using namespace std;

int main() {
    int num;
    while (cin >> num) {
        if (num == 0)
            break;

        cout << num / 2 << endl;
    }

    return 0;
}