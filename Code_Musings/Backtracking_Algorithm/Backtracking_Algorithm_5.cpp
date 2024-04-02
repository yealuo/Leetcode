#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    const vector<string> map{
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string path;
    vector<string> result;

    void backTracking(const string &digits,int index){
        if (index == digits.size()) {
            if (!path.empty()) {
                result.push_back(path);
            }
            return;
        }

        int digit = digits[index] - '0';
        string letter = map[digit];
        for (int i = 0; i < letter.size(); ++i) {
            path.push_back(letter[i]);
            backTracking(digits, index + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        backTracking(digits, 0);
        return result;
    }
};
