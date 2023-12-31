#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i <= nums.size(); ++i) {
            result ^= i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }

        return result;
    }
};

int main() {
    return 0;
}