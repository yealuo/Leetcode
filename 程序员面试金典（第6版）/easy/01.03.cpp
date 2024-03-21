#include <iostream>
#include <string>
using namespace std;

string replaceSpaces_1(string S, int length) {
    string result;
    for (int i = 0; i < length; ++i) {
        if (S[i] != ' ') {
            result += S[i];
        } else {
            result += "%20";
        }
    }
    return result;
}

string replaceSpaces_2(string S, int length) {
    if (length == 0) {
        return S;
    }
    int left = length - 1;
    int right = S.size() - 1;
    for (; left >= 0; --left) {
        if (S[left] == ' ') {
            S[right] = '0';
            S[--right] = '2';
            S[--right] = '%';
            --right;
        } else {
            S[right--] = S[left];
        }
    }
    S = S.substr(right + 1);
    return S;
}

int main() {
    return 0;
}