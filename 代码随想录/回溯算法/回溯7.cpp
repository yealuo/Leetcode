#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    
    int add(vector<int> vec) {
        int result = 0;
        for (int i : vec) {
            result += i;
        }
        return result;
    }

    void backTracking(vector<int>& candidates, int target, int startIndex) {
        if (add(path) == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            if (i != startIndex && candidates[i] == candidates[i - 1]) {    //Ê÷²ãÈ¥ÖØ
                continue;
            }

            if (add(path) + candidates[i] > target) {
                return;
            }

            path.push_back(candidates[i]);
            backTracking(candidates, target, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0);
        return result;
    }
};
