#include <iostream>
#include <string>
using namespace std;

string compressString(string S) {
    if (S.size() < 3) {
        return S;
    }
    string compactString;
    int count = 0;
    for (auto left = S.begin(), right = S.begin(); right != S.end(); ++right) {
        if (*left == *right) {
            ++count;
        } else {
            compactString += *left + to_string(count);
            left = right;
            count = 1;
        }
        if (compactString.size() >= S.size()) {
            return S;
        }
        if (right + 1 == S.end()) {
            compactString += *left + to_string(count);
        }
    }
    return compactString.size() < S.size() ? compactString : S;
}

int main() {
    cout << compressString("aabcccccaaa") << endl;
    return 0;
}