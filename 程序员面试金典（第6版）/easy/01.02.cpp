#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool CheckPermutation_1(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    int count[26] = {0};
    for (auto& alpha : s1) {
        ++count[alpha - 'a'];
    }
    for (auto& alpha : s2) {
        --count[alpha - 'a'];
        if (count[alpha - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

bool CheckPermutation_2(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    return 0;
}