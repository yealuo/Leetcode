#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    int add(vector<int> vec) {
        int result = 0;
        for (int i = 0; i < vec.size(); ++i) {
            result += vec[i];
        }
        return result;
    }

    void backTracking(int k,int n,int startIndex){
        if (path.size() == k) {
            if (add(path) == n) {
                result.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9-(k-path.size())+1; ++i) {
            if (add(path) + i > n) {    //ºÙ÷¶
                return;
            }
            path.push_back(i);
            backTracking(k,n,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1);
        return result;
    }
};