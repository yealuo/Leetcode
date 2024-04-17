//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <string>

using namespace std;

bool is_valid(int num) {
    int temp = num * num;
    string str(to_string(temp));
    return str.substr(str.size() - to_string(num).size(), to_string(num).size()) == to_string(num);
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i <= n; ++i) {
        if (is_valid(i))
            ++count;
    }

    cout << count;

    return 0;
}