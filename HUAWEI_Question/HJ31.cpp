//
// Created by Administrator on 2024/4/9.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    int prev = 0, curt = 0;
    vector<string> word;
    for (; curt < in.size(); ++curt) {
        if (!isalpha(in[curt])) {
            word.emplace_back(in.begin() + prev, in.begin() + curt);
            prev = curt + 1;
        }
    }
    word.emplace_back(in.begin() + prev, in.begin() + curt);

    for (int i = word.size() - 1; i >= 0; --i) {
        cout << word[i] << " ";
    }

    return 0;
}