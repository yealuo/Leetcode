#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    int add(vector<int> vec) {
        int result = 0;
        for (const int i : vec) {
            result += i;
        }
        return result;
    }

    void backTracking(const vector<int>& candidates,const int target,const int index){
        if (add(path) == target) {
            result.push_back(path);
            return;
        }


        for (int i = index; i < candidates.size();++i) {
            if (add(path) + candidates[i] > target) {
                continue;
            }
            path.push_back(candidates[i]);
            backTracking(candidates, target,i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target,0);
        return result;
    }
};