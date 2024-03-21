#include <bitset>
#include <iostream>
using namespace std;

class Solution {
   public:
    int insertBits1(int N, int M, int i, int j) {
        bitset<32> n(N);
        bitset<32> m(M);

        for (int count1 = i, count2 = 0; count1 <= j; ++count1, ++count2) {
            n[count1] = m[count2];
        }

        return n.to_ulong();
    }

    int insertBits(int N, int M, int i, int j) {
        for (int count = i; count <= j; ++count) {
            N &= ~(1 << count);
        }

        return N+(M<<i);
    }
};

int main() {
    Solution test;
    cout << test.insertBits(1024, 19, 2, 6) << endl;
    return 0;
}