#include <iostream>
using namespace std;

class Solution1 {
   public:
    int trailingZeroes(int n) {
        int count_5 = 0;

        for (long i = 5; i <= n; i += 5) {
            int temp = i;

            while (temp % 5 == 0) {
                temp /= 5;
                ++count_5;
            }
        }

        return count_5;
    }
};

class Solution {
   public:
    int trailingZeroes(int n) {
        int count_5 = 0;

        while (n != 0) {
            n /= 5;
            count_5 += n;
        }

        return count_5;
    }
};

int main() {
    Solution test;
    cout << test.trailingZeroes(2147483647) << endl;
    return 0;
}