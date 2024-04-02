#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        int size = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3; ++i) {
            // 一重剪枝
            if (nums[i] >= 0 && nums[i] > target) {
                return result;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < size - 2; ++j) {
                // 二重剪枝
                if (nums[j] >= 0 && nums[i] + nums[j] > target) {
                    break;
                }

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1, right = nums.size() - 1;

                while (left < right) {
                    if (static_cast<long>(nums[i]) +
                            static_cast<long>(nums[j]) +
                            static_cast<long>(nums[left]) +
                            static_cast<long>(nums[right]) <
                        target) {
                        ++left;
                    } else if (static_cast<long>(nums[i]) +
                                   static_cast<long>(nums[j]) +
                                   static_cast<long>(nums[left]) +
                                   static_cast<long>(nums[right]) >
                               target) {
                        --right;
                    } else {
                        result.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) {
                            ++left;
                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                            --right;
                        }

                        ++left;
                        --right;
                    }
                }
            }
        }

        return result;
    }
};

