#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backTracking(const vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        if (startIndex == nums.size()) {
            return;
        }

        unordered_set<int> ifExist;    //������飬�ж����������ظ�
        for (int i = startIndex; i < nums.size(); ++i) {
            if (ifExist.find(nums[i]) != ifExist.end()) {   //ȥ��
                continue;
            }

            if (path.empty() || (nums[i] >= path[path.size() - 1])) {
                path.push_back(nums[i]);
                ifExist.insert(nums[i]);
                backTracking(nums, i + 1);
                path.pop_back();
            }
            else {
                continue;
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};
