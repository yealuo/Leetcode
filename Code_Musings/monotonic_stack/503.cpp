//
// Created by Administrator on 2024/4/19.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size() * 2; ++i) {
            int n = i % nums.size();
            if (st.empty())
                st.push(n);
            else {
                if (nums[n] > nums[st.top()]) {
                    while (!st.empty() && nums[n] > nums[st.top()]) {
                        res[st.top()] = nums[n];
                        st.pop();
                    }
                    st.push(n);
                } else {
                    st.push(n);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> t{1, 2, 1};
    s.nextGreaterElements(t);
    return 0;
}