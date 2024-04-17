//
// Created by Administrator on 2024/4/16.
//
#include <iostream>

using namespace std;

int main() {
    int lines, columns;
    while (cin >> lines >> columns) {
        if ((lines >= 0 && lines <= 9) && (columns >= 0 && columns <= 9))
            cout << 0 << endl;
        else
            cout << -1 << endl;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 >= 0 && x1 < lines) && (y1 >= 0 && y1 < columns) && (x2 >= 0 && x2 < lines) &&
            (y2 >= 0 && y2 < columns))
            cout << 0 << endl;
        else
            cout << -1 << endl;

        int insert_line;
        cin >> insert_line;
        if (lines < 9 && (insert_line >= 0 && insert_line <= lines - 1))
            cout << 0 << endl;
        else
            cout << -1 << endl;

        int insert_column;
        cin >> insert_column;
        if (columns < 9 && (insert_column >= 0 && insert_column <= columns - 1))
            cout << 0 << endl;
        else
            cout << -1 << endl;

        int t_x, t_y;
        cin >> t_x >> t_y;
        if ((t_x >= 0 && t_x < lines) && (t_y >= 0 && t_y < columns))
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}