//
// Created by Administrator on 2024/4/14.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<vector<int>> matrix1(x, vector<int>(y)), matrix2(y, vector<int>(z)), result(x, vector<int>(z, 0));

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            cin >> matrix1[i][j];
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < z; ++j)
            cin >> matrix2[i][j];
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < z; ++j) {
            for (int k = 0; k < y; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }

    for (const auto &line: result) {
        for (const auto &num: line)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}