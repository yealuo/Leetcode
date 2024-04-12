//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 7 == 0)
            ++count;
        else {
            string str = to_string(i);
            if (str.find('7') != string::npos)
                ++count;
        }
    }

    cout << count;

    return 0;
}