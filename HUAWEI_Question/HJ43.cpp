//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <vector>

using namespace std;

bool backtracking(vector<vector<int>> &maze, vector<pair<int, int>> &path, int x, int y) {
    if (x == maze.size() - 1 && y == maze[0].size() - 1)
        return true;

    if (x - 1 >= 0 && maze[x - 1][y] != 1) {
        maze[x][y] = 1;
        path.emplace_back(x - 1, y);
        if (backtracking(maze, path, x - 1, y))
            return true;
        else
            path.pop_back();
    }
    if (x + 1 < maze.size() && maze[x + 1][y] != 1) {
        maze[x][y] = 1;
        path.emplace_back(x + 1, y);
        if (backtracking(maze, path, x + 1, y))
            return true;
        else
            path.pop_back();
    }
    if (y - 1 >= 0 && maze[x][y - 1] != 1) {
        maze[x][y] = 1;
        path.emplace_back(x, y - 1);
        if (backtracking(maze, path, x, y - 1))
            return true;
        else
            path.pop_back();
    }
    if (y + 1 < maze[0].size() && maze[x][y + 1] != 1) {
        maze[x][y] = 1;
        path.emplace_back(x, y + 1);
        if (backtracking(maze, path, x, y + 1))
            return true;
        else
            path.pop_back();
    }

    return false;
}

int main() {
    int line_num, column_num;
    cin >> line_num >> column_num;
    vector<vector<int>> maze(line_num, vector<int>(column_num));
    for (int i = 0; i < line_num; ++i) {
        for (int j = 0; j < column_num; ++j)
            cin >> maze[i][j];
    }

    vector<pair<int, int>> path;
    path.emplace_back(0, 0); //从(0,0)开始
    if (backtracking(maze, path, 0, 0)) {
        for (const auto &elem: path)
            cout << '(' << elem.first << ',' << elem.second << ')' << endl;
    }

    return 0;
}