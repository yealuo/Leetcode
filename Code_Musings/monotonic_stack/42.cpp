//
// Created by Administrator on 2024/4/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty())
                st.push(i);
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int w = i - st.top() - 1;
                        int h = min(height[i], height[st.top()]) - height[mid];
                        sum += w * h;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}