//
// Created by Administrator on 2024/4/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); ++i) {
            m[nums1[i]] = i;
        }

        vector<int> result(nums1.size(), -1);
        stack<int> st;
        for (int i = 0; i < nums2.size(); ++i) {
            if (st.empty()) {
                st.push(i);
            } else {
                if (nums2[i] > nums2[st.top()]) {
                    while (!st.empty() && nums2[i] > nums2[st.top()]) {
                        if (m.count(nums2[st.top()]) != 0) {
                            result[m[nums2[st.top()]]] = nums2[i];
                        }
                        st.pop();
                    }
                    st.push(i);
                } else {
                    st.push(i);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution t;
    vector<int> a1{2, 4}, a2{1, 2, 3, 4};
    t.nextGreaterElement(a1, a2);
    return 0;
}