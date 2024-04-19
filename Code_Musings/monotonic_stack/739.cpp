//
// Created by Administrator on 2024/4/18.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            if (st.empty())
                st.push(i);
            else {
                if (temperatures[i] > temperatures[st.top()]) {
                    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                        result[st.top()] = i - st.top();
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
    return 0;
}