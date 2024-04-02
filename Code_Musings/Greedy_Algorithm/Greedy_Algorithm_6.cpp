#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int cur = 0;
        int next = 0;
        int result=0;
        for (int i = 0; i < nums.size(); ++i) {
            next = max((i + nums[i]),next);
            if (i == cur) {
                if (cur != nums.size() - 1) {
                    ++result;
                    cur = next;
                    if (cur >= nums.size() - 1) {
                        break;
                    }
                }
                else {
                    break;
                }
            }

        }
        return result;
    }
};

class Solution {
private:
    int count = 0;

    void backTracking(const vector<int>& nums, int begin_index) {
        if (begin_index + nums[begin_index] >= nums.size() - 1) {
            ++count;
            return;
        }

        int max_range = 0;
        int max_index = 0;
        for (int i = begin_index + 1; i <= begin_index + nums[begin_index]; ++i) {
            if (i + nums[i] > max_range) {
                max_range = i + nums[i];
                max_index = i;
            }
        }
        ++count;
        backTracking(nums, max_index);
    }

public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        backTracking(nums, 0);
        return count;
    }
};
