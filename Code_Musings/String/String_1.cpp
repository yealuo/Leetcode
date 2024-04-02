#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1 - i; i < s.size() && i < j; ++i, --j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};

int main() {
    return 0;
}
