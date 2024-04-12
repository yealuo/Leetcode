//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const vector<vector<int>> &sudoku, int x, int y, int num) {
    //检查行
    for (int i = 0; i < 9; ++i) {
        if (i != y) {
            if (sudoku[x][i] == num)
                return false;
        }
    }

    //检查列
    for (int i = 0; i < 9; ++i) {
        if (i != x) {
            if (sudoku[i][y] == num)
                return false;
        }
    }

    //检查九宫格内
    int base_x = x / 3 * 3, base_y = y / 3 * 3; //小九宫格的最左上角坐标
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (base_x + i != x || base_y != y) {
                if (sudoku[base_x + i][base_y + j] == num)
                    return false;
            }
        }
    }

    return true;
}

bool back_tracking(vector<vector<int>> &sudoku) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudoku[i][j] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(sudoku, i, j, num)) {
                        sudoku[i][j] = num;
                        if (back_tracking(sudoku))
                            return true;
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cin >> sudoku[i][j];
    }

    if (back_tracking(sudoku)) {
        for (const auto &line: sudoku) {
            for (const auto &column: line) {
                cout << column << " ";
            }
            cout << endl;
        }
    }

    return 0;
}