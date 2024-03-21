#include <bitset>
#include <iostream>
using namespace std;

class Solution {
   public:
    int maximum(long long a, long long b) {
        bitset<64> sub(a - b);

        return sub[63] == 0 ? a : b;
    }
};

int main() {
    return 0;
}