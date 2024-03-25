#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;

    bool isValid(const string& sub) {
        if (sub.size() == 1) {
            return true;
        }
        else if (sub[0]=='0') {
            return false;
        }
        else {
            int num = stoi(sub);
            if (num <= 255) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    void backTracking(const string& s, int startIndex) {
        if (startIndex == s.size()) {
            if (path.size() < 4) {
                return;
            }
            else {
                result.push_back(path);
                return;
            }
        }

        for (int i = startIndex; i < s.size()&&(i-startIndex+1<4); ++i) {
            if (path.size()==4&&startIndex!=s.size()) {
                return;
            }
            const string sub = string(s.begin() + startIndex, s.begin() + i + 1);
            if (isValid(sub)) {
                path.push_back(sub);
            }
            else {
                return;
            }

            backTracking(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0);
        vector<string> res;
        string ip;
        for (const auto &path : result) {
            for (const auto &i : path) {
                ip = ip + i + ".";
            }
            ip.erase(ip.end() - 1);
            res.push_back(ip);
            ip.clear();
        }

        return res;
    }
};

class Solution1 {
private:
    vector<string> path;
    vector<vector<string>> result;

    bool isValid(const string& sub) {
        if (sub.empty()) {
            return false;
        }
        else if (sub.size() == 1) {
            return true;
        }
        else if (sub[0] == '0') {
            return false;
        }
        else if (stoll(sub) <= 255) {
            return true;
        }
        else {
            return false;
        }
    }

    void backTracking(const string& s, int startIndex, int count) {
        if (count == 3) {
            const string sub = string(s.begin() + startIndex, s.end());
            if (isValid(sub)) {
                path.push_back(sub);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }

        for (int i = startIndex; i < s.size()&&(i-startIndex+1<4); ++i) {
            const string sub = string(s.begin() + startIndex, s.begin() + i + 1);
            if (isValid(sub)) {
                path.push_back(sub);
                backTracking(s, i + 1, count + 1);
                path.pop_back();
            }
            else {
                return;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);
        vector<string> res;
        string ip;
        for (const auto& path : result) {
            for (const auto& i : path) {
                ip = ip + i + ".";
            }
            ip.erase(ip.end() - 1);
            res.push_back(ip);
            ip.clear();
        }

        return res;
    }
};
