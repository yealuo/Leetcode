//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    cin >> in;

    for (int i = 0; i < in.size(); ++i) {
        if (!isdigit(in[i])) {
            continue;
        } else {
            in.insert(i, "*");
            ++i;
            while (isdigit(in[i])) {
                ++i;
            }
            in.insert(i, "*");
        }
    }

    cout << in;

    return 0;
}