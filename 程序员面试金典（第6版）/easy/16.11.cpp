#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution1 {
   public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        set<int> temp;

        if (k == 0) {
            return vector<int>();
        } else if (shorter == longer) {
            return vector<int>{shorter * k};
        }

        for (int i = 0; i <= k; ++i) {
            if (temp.find(i * longer + (k - i) * shorter) == temp.end()) {
                temp.insert(i * longer + (k - i) * shorter);
            }
        }

        return vector<int>(temp.begin(), temp.end());
    }
};

class Solution {
   public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;

        if (k == 0) {
            return vector<int>();
        } else if (shorter == longer) {
            return vector<int>{shorter * k};
        }

        for (int i = 0; i <= k; ++i) {
            result.push_back(i * longer + (k - i) * shorter);
        }

        return result;
    }
};

int main() {
    return 0;
}