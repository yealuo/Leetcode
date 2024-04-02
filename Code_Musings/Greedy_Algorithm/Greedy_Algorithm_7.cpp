#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		int index = 0;
		while (k != 0) {
			sort(nums.begin(), nums.end());
			nums[0] = -nums[0];
			--k;
		}

		int result = 0;
		for (const auto& num : nums) {
			result += num;
		}

		return result;
	}
};

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()&&nums[i]<0; ++i) {
			if (nums[i] < 0 && k>0) {
				nums[i] = -nums[i];
				--k;
			}
			if (k == 0) {
				break;
			}
		}

		if (k != 0) {
			sort(nums.begin(), nums.end());
			if (k % 2 == 1) {
				nums[0] = -nums[0];
			}
		}

		int result = 0;
		for (const auto& num : nums) {
			result += num;
		}

		return result;
	}
};
