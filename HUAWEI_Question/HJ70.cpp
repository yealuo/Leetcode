//
// Created by Administrator on 2024/4/14.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline int cal(const vector<int> &mat1, const vector<int> &mat2) {
    return mat1[0] * mat1[1] * mat2[1];
}

int main() {
    int count;
    cin >> count;

    vector<vector<int>> detail(count, vector<int>(2));
    for (int i = 0; i < count; ++i)
        cin >> detail[i][0] >> detail[i][1];

    string exp;
    cin >> exp;

    stack<char> mat;
    int result = 0;
    for (const auto &elem: exp) {
        if (elem == ')') {
            vector<int> mat2 = detail[mat.top() - 'A'];
            mat.pop();
            vector<int> mat1 = detail[mat.top() - 'A'];
            mat.pop();
            result += cal(mat1, mat2);
            detail.push_back({mat1[0], mat2[1]});
            mat.push('A' + detail.size() - 1);
        } else if (elem != '(')
            mat.push(elem);
    }

    cout << result;

    return 0;
}