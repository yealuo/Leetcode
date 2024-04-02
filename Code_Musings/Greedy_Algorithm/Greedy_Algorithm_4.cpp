#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int diff = 0;
        for (int i = 0; i < prices.size()-1; ++i) {
            diff = prices[i + 1] - prices[i];
            if (diff > 0) {
                result += diff;
            }
        }
        return result;
    }
};
