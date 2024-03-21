#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> arr(nums.size() + 1);

        arr[0] = 0;
        arr[1] = nums[0];

        for (int i = 2; i <= nums.size(); ++i) {
            arr[i] = max(arr[i - 1], arr[i - 2] + nums[i - 1]);
        }

        return arr.back();
    }
};

int main() {
    return 0;
}