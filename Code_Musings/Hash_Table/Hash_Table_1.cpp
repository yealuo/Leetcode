#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
   public:
    bool isAnagram(string s, string t) {
        if (s == t) {
            return true;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26, 0);

        for (auto& elem : s) {
            ++hash[elem - 'a'];
        }

        for (auto& elem : t) {
            --hash[elem - 'a'];
        }

        for (auto& elem : hash) {
            if (elem != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}
