#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) {
            return {{1}};
        }

        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = 1;

        for (int i = 0; i < n / 2; ++i) {
            for (int a = 0; a < n - i * 2 - 1; ++a) {
                result[i][i + a] = count;
                result[i + a][n - 1 - i] = count + n - i * 2 - 1;
                result[n - 1 - i][n - 1 - i - a] = count + 2 * (n - i * 2 - 1);
                result[n - 1 - i - a][i] = count + 3 * (n - i * 2 - 1);
                count += 1;
            }
            count = result[i + 1][i] + 1;
        }

        if (result[n / 2][n / 2] == 0) {
            result[n / 2][n / 2] = result[n / 2][n / 2 - 1] + 1;
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = 1;

        for (int i = 0; i < n / 2; ++i) {
            for (int a = 0; a < n - i * 2 - 1; ++a) {
                result[i][i + a] = count;
                ++count;
            }

            for (int a = 0; a < n - i * 2 - 1; ++a) {
                result[i + a][n - 1 - i] = count;
                ++count;
            }

            for (int a = 0; a < n - i * 2 - 1; ++a) {
                result[n - 1 - i][n - 1 - i - a] = count;
                ++count;
            }

            for (int a = 0; a < n - i * 2 - 1; ++a) {
                result[n - 1 - i - a][i] = count;
                ++count;
            }
        }

        if (result[n / 2][n / 2] == 0) {
            result[n / 2][n / 2] = count;
        }

        return result;
    }
};

int main() {
    Solution test;
    test.generateMatrix(4);
    return 0;
}