#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0;
        int total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur_sum += (gas[i] - cost[i]);
            total_sum+= (gas[i] - cost[i]);
            if (cur_sum < 0) {
                start = i + 1;
                cur_sum = 0;
            }
        }

        if (total_sum < 0) {
            return -1;
        }

        return start;
    }
};
