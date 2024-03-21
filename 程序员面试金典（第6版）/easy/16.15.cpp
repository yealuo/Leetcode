#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> masterMind(string solution, string guess) {
        int count = 0, pseudo_count = 0;
        unordered_map<char, int> map;

        // 猜中
        for (int i = 0; i < solution.size(); ++i) {
            if (solution[i] == guess[i]) {
                ++count;
                solution.erase(solution.begin() + i);
                guess.erase(guess.begin() + i);
                --i;
            } else {
                if (map.find(solution[i]) == map.end()) {
                    map[solution[i]] = 1;
                } else {
                    ++map[solution[i]];
                }
            }
        }

        // 伪猜中
        for (int j = 0; j < guess.size(); ++j) {
            if (map.find(guess[j]) != map.end() && map[guess[j]] > 0) {
                ++pseudo_count;
                --map[guess[j]];
            }
        }

        return {count, pseudo_count};
    }
};

int main() {
    return 0;
}