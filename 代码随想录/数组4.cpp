#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, l = 0, length = 0, minLength = INT_MAX;

        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];

            while (sum >= target) {
                length = r - l + 1;
                minLength = min(minLength, length);
                sum -= nums[l];
                ++l;
            }
        }

        if (minLength == INT_MAX) {
            return 0;
        } else {
            return minLength;
        }
    }
};

int main() {
    return 0;
}