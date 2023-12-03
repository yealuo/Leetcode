#include <bitset>
#include <iostream>
#include <string>
using namespace std;

bool canPermutePalindrome_1(string s) {
    if (s.size() <= 1) {
        return true;
    }
    int count[128] = {0};
    for (auto& alpha : s) {
        ++count[alpha];
    }
    int oddCount = 0;
    for (auto& num : count) {
        if (num % 2 == 1) {
            ++oddCount;
            if (oddCount > 1) {
                return false;
            }
        }
    }
    return true;
}

bool canPermutePalindrome_2(string s) {
    if (s.size() <= 1) {
        return true;
    }
    bitset<128> flag;
    for (auto& alpha : s) {
        flag[alpha] = flag[alpha] ^ 1;
    }
    return flag.count() < 2;
}

int main() {
    canPermutePalindrome_2("code");
    return 0;
}