#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        vector<int> result;

        for (auto& elem : nums1) {
            hash.emplace(elem);
        }

        for (auto& elem : nums2) {
            if (hash.find(elem) != hash.end()) {
                result.emplace_back(elem);
                hash.erase(elem);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}