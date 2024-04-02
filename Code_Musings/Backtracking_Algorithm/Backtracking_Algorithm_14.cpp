#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    
    void backTracking(const vector<int>& nums,vector<int>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && used[i - 1] == 0 && nums[i] == nums[i - 1]) {  //����ȥ��
                continue;
            }
            if (used[i] == 0) {
                path.push_back(nums[i]);
                used[i] = 1;
                backTracking(nums, used);
                used[i] = 0;
                path.pop_back();
            }
            else {
                continue;
            }
        }
    }


public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return result;
    }
};
