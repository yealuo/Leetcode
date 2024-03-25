#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backTracking(vector<int>& nums, int startIndex) {
        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            result.push_back(path);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);
        result.push_back(vector<int>());
        return result;
    }
};