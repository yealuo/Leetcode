#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        int count = 0;
        int curt = nums[0];
        int mainElem;

        for (auto& elem : nums) {
            if (elem == curt) {
                ++count;

                if (count > maxCount) {
                    maxCount = count;
                    mainElem = curt;
                }
            } else {
                curt = elem;
                count = 1;
            }
        }

        if (maxCount <= nums.size() / 2) {
            return -1;
        } else {
            return mainElem;
        }
    }
};

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;

        for (auto& elem : nums) {
            if (elem == candidate) {
                ++count;
            } else if (elem != candidate && count != 0) {
                --count;
            } else {
                candidate = elem;
                count = 1;
            }
        }

        count = 0;

        for (auto& elem : nums) {
            if (elem == candidate) {
                ++count;
            }
        }

        if (count > nums.size() / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution test;
    vector<int> v{3, 2, 3};
    test.majorityElement(v);
    return 0;
}