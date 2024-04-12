//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<vector<int>> result(num, vector<int>(num, 0));
    int count = 1;
    for (int line = 0; line < num; ++line) {
        for (int column = 0; column <= line; ++column) {
            result[line - column][column] = (count++);
        }
    }

    for (const auto &line: result) {
        for (const auto &column: line) {
            if (column != 0)
                cout << column << " ";
        }
        cout << endl;
    }

    return 0;
}