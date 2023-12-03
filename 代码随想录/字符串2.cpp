#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   private:
    void reverse(string& s, int l, int r) {
        if (r > s.size()) {
            r = s.size();
        }

        --r;

        for (; l < r; ++l, --r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    }

   public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s, i, i + k);
        }

        return s;
    }
};

int main() {
    return 0;
}