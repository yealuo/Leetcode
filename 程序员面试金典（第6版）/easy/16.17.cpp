#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            maxSum = max(maxSum, nums[i]);
        }

        return maxSum;
    }
};

int main() {
    return 0;
}