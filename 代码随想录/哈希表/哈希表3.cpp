#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash.find(target - nums[i]);

            if (it != hash.end()) {
                return {it->second, i};
            } else {
                hash[nums[i]] = i;
            }
        }

        return {};
    }
};

