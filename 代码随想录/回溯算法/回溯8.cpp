#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;

    bool isBalanced(const string& s) {
        for (auto begin = s.begin(), end = s.end()-1; begin <= end; ++begin, --end) {
            if (*begin != *end) {
                return false;
            }
        }
        return true;
    }

    void backTracking(const string &s,int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); ++i) {
            const string subString = string(s.begin() + startIndex, s.begin() + i + 1);
            if (isBalanced(subString)) {
                path.push_back(subString);
            }
            else {
                continue;
            }

            backTracking(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};