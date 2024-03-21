#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int waysToStep1(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 4;
        }

        vector<long> result(n + 1);

        result[1] = 1;
        result[2] = 2;
        result[3] = 4;

        for (int i = 4; i <= n; ++i) {
            result[i] =
                ((result[i - 1] + result[i - 2]) % 1000000007 + result[i - 3]) %
                1000000007;
        }

        return result[n];
    }

    // 矩阵快速幂方法
    using Row = vector<long>;
    using Matrix = vector<Row>;

    // 矩阵乘法
    Matrix matrixMultiply(const Matrix& a, const Matrix& b) {
        int aRow = a.size();                   // a的行数
        int bRow = b.size();                   // b的行数
        int bColumn = b[0].size();             // b的列数
        int aColumn = a[0].size();             // a的列数
        Matrix result(aRow, Row(bColumn, 0));  // 结果矩阵

        if (aColumn != bRow) {
            cerr << "这两个矩阵不能相乘！" << endl;
            return {};
        }

        for (int ar = 0; ar < aRow; ++ar) {
            for (int bc = 0; bc < bColumn; ++bc) {
                for (int ac = 0; ac < aColumn; ++ac) {
                    result[ar][bc] += a[ar][ac] * b[ac][bc];
                    result[ar][bc] = result[ar][bc] % 1000000007;
                }
            }
        }

        return result;
    }
    //  矩阵快速幂
    Matrix fastMatrixPower(Matrix matrix, int power) {
        if (power == 1) {
            return matrix;
        }

        if (power % 2 == 0) {
            Matrix temp = fastMatrixPower(matrix, power / 2);

            return matrixMultiply(temp, temp);
        } else {
            Matrix temp = fastMatrixPower(matrix, (power - 1) / 2);

            return matrixMultiply(matrixMultiply(temp, temp), matrix);
        }
    }

    // 解决方法
    int waysToStep(int n) {
        // 初始矩阵
        Row row = {1, 2, 4};
        Matrix origin = {row, {0, 0, 0}, {0, 0, 0}};

        // 工具矩阵
        Matrix tool = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};

        // 结果矩阵
        if (n <= 0) {
            return -1;
        } else if (n <= 3) {
            return row[n - 1];
        } else {
            Matrix result =
                matrixMultiply(origin, fastMatrixPower(tool, n - 3));
            return result[0][2];
        }
    }
};

int main() {
    Solution test;
    cout << test.waysToStep(61) << endl;
    return 0;
}