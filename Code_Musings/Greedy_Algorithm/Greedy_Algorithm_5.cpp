#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        int i = 0;
        while (i <= range) {
            range = max(range, (i + nums[i]));
            if (range >= nums.size() - 1) {
                return true;
            }
            ++i;
        }
        return false;
    }
};
