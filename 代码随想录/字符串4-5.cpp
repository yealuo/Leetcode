#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP {
   private:
    vector<int> getNext(const string& pattern) {
        vector<int> next(pattern.size());
        next[0] = 0;
        int left = 0;

        for (int right = 1; right < pattern.size(); ++right) {
            while (left > 0 && pattern[left] != pattern[right]) {
                left = next[left - 1];
            }

            if (pattern[left] == pattern[right]) {
                ++left;
            }

            next[right] = left;
        }

        return next;
    }

   public:
    int kmp(string textStr, string patternStr) {
        if (patternStr.empty()) {
            return 0;
        }

        vector<int> next = getNext(patternStr);
        int textPtr = 0, patternPtr = 0;

        while (textPtr < textStr.size()) {
            if (textStr[textPtr] == patternStr[patternPtr]) {
                ++textPtr;
                ++patternPtr;
            } else if (patternPtr > 0) {
                patternPtr = next[patternPtr - 1];
            } else {
                ++textPtr;
            }

            if (patternPtr == patternStr.size()) {
                return textPtr - patternPtr;
            }
        }

        return -1;
    }
};

int main() {
    KMP test;
    test.kmp("babba", "bbb");
    return 0;
}