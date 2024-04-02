#include<iostream>
#include<vector>

using namespace std;

class Solution {
/*
 *����Ҫ�������������
 *���һ������������ƽ��
 *�������������β����
 *�����������������ƽ��
*/
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int pre_diff = 0;
        int curt_diff = 0;
        int result = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curt_diff = nums[i + 1] - nums[i];
            if ((pre_diff <= 0 && curt_diff > 0) || (pre_diff >= 0 && curt_diff < 0)) {
                ++result;
                pre_diff = curt_diff;
            }
        }

        return result;
    }
};
