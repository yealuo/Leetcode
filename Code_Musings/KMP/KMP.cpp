#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP {
   private:
    vector<int> getNext(string pattern) {
        vector<int> next(pattern.size());
        next[0] = 0;
        int left = 0;

        for (int right = 1; right < pattern.size(); ++right) {
            while (left > 0 && pattern[left] != pattern[right]) {
                left = next[left - 1];
            }

            if (pattern[left] = pattern[right]) {
                ++left;
            }

            next[right] = left;
        }

        return next;
    }

   public:
    int kmp(string text, string pattern) {
        if (pattern.empty()) {
            return 0;
        }

        vector<int> next = getNext(pattern);
        int textPtr = 0, patternPtr = 0;

        while (textPtr < text.size()) {
            if (text[textPtr] == pattern[patternPtr]) {
                ++textPtr;
                ++patternPtr;
            } else if (patternPtr > 0) {
                patternPtr = next[patternPtr - 1];
            } else {
                ++textPtr;
            }

            if (patternPtr == pattern.size()) {
                return textPtr - patternPtr;
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}
