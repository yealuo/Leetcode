#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;

    bool isValid(const vector<string>& chessBoard,const int n,const int row,const int column) {
        //�м��
        for (int r = row-1; r >= 0; --r) {
            if (chessBoard[r][column] == 'Q') {
                return false;
            }
        }

        //б�߼��
        int temp_row = row;
        int temp_column = column;
        while (temp_row != 0 && temp_column != 0) {
            --temp_row;
            --temp_column;
            if (chessBoard[temp_row][temp_column] == 'Q') {
                return false;
            }
        }

        temp_row = row;
        temp_column = column;
        while (temp_row != 0 && temp_column != n-1) {
            --temp_row;
            ++temp_column;
            if (chessBoard[temp_row][temp_column] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backTracking(vector<string>& chessBoard,const int n,const int row) {
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }

        for (int column = 0; column < n; ++column) {
            if (isValid(chessBoard, n, row, column)) {
                chessBoard[row][column] = 'Q';
                backTracking(chessBoard, n, row + 1);
                chessBoard[row][column] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n,string(n,'.'));
        backTracking(chessBoard, n, 0);
        return result;
    }
};
