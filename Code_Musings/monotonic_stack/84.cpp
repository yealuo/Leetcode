//
// Created by Administrator on 2024/4/19.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);
        stack<int> st;
        int max = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (st.empty())
                st.push(i);
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int l = st.top();
                        int w = i - l - 1;
                        int h = heights[mid];
                        max = max > w * h ? max : w * h;
                    }
                }
                st.push(i);
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> t{2, 2, 1};
    s.largestRectangleArea(t);
    return 0;
}