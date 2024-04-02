#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for (int j = ratings.size() - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                candy[j] = max(candy[j + 1] + 1,candy[j]);
            }
        }

        int result = 0;
        for (int i : candy) {
            result += i;
        }

        return result;
    }
};
