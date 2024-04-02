#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	bool isValid(vector<vector<char>>& board, const int row, const int column, const char num) {
		//�м��
		for (int temp_column = 0; temp_column < board.size(); ++temp_column) {
			if (board[row][temp_column] == num) {
				return false;
			}
		}

		//�м��
		for (int temp_row = 0; temp_row < board.size(); ++temp_row) {
			if (board[temp_row][column] == num) {
				return false;
			}
		}

		//�Ź�����
		int sudoku_row = row / 3;
		int sudoku_column = column / 3;
		for (int r = sudoku_row * 3; r < (sudoku_row + 1) * 3; ++r) {
			for (int c = sudoku_column * 3; c < (sudoku_column + 1) * 3; ++c) {
				if (board[r][c] == num) {
					return false;
				}
			}
		}

		return true;
	}

	bool backTracking(vector<vector<char>>& board) {
		for (int row = 0; row < board.size(); ++row) {
			for (int column = 0; column < board.size(); ++column) {
				if (board[row][column] != '.') {
					continue;
				}

				for (char num = '1'; num <= '9'; ++num) {
					if (isValid(board, row, column, num)) {
						board[row][column] = num;
						if (backTracking(board)) {
							return true;
						}
						board[row][column] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		backTracking(board);
	}

};
