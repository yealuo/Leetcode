#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    bool oneEditAway(string first, string second) {
        if (first.size() < second.size()) {
            string temp = first;
            first = second;
            second = temp;
        }

        if (first.size() - second.size() > 1) {
            return false;
        }

        int count = 0;

        if (first.size() == second.size()) {
            for (int i = 0; i < first.size(); ++i) {
                if (first[i] != second[i]) {
                    ++count;
                }

                if (count > 1) {
                    return false;
                }
            }

            return true;
        }

        for (int i = 0, j = 0; i < first.size() && j < second.size();
             ++i, ++j) {
            if (first[i] != second[j]) {
                ++count;
                --j;
            }

            if (count > 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}