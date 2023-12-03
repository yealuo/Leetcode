#include <iostream>
#include <vector>
using namespace std;

// 递归
class Solution1 {
   public:
    int help(vector<string>& words, string s, int left, int right) {
        while (left <= right && words[left] == "") {
            ++left;
        }
        while (left <= right && words[right] == "") {
            --right;
        }

        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        while (words[mid] == "" && mid <= right) {
            ++mid;
        }

        if (words[mid] == s) {
            return mid;
        } else if (words[mid] > s) {
            return help(words, s, left, mid - 1);
        } else {
            return help(words, s, mid + 1, right);
        }
    }

    int findString(vector<string>& words, string s) {
        return help(words, s, 0, words.size() - 1);
    }
};

// 迭代
class Solution {
   public:
    int findString(vector<string>& words, string s) {
        int l = 0;
        int r = words.size() - 1;

        while (l <= r && words[l] == "") {
            ++l;
        }
        while (l <= r && words[r] == "") {
            --r;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;

            while (mid <= r && words[mid] == "") {
                ++mid;
            }

            if (words[mid] == s) {
                return mid;
            } else if (words[mid] > s) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            while (l <= r && words[l] == "") {
                ++l;
            }
            while (l <= r && words[r] == "") {
                --r;
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}