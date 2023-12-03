#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   private:
    // 去掉首位空格
    void removeSpace(string& s) {
        int slow = 0;

        for (int fast = 0; fast < s.size(); ++fast) {
            if (s[fast] == ' ') {
                continue;
            }

            if (slow != 0) {
                s[slow++] = ' ';
            }

            while (fast < s.size() && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }

        s.resize(slow);
    }

   public:
    string reverseWords(string s) {
        removeSpace(s);

        reverse(s.begin(), s.end());

        auto preIt = s.begin();

        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == ' ') {
                reverse(preIt, it);
                preIt = it + 1;
            }
        }

        reverse(preIt, s.end());

        return s;
    }
};

int main() {
    return 0;
}