//
// Created by Administrator on 2024/4/9.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<string> dict;
    while (n--) {
        string in;
        cin >> in;
        dict.push_back(in);
    }
    string origin_word;
    cin >> origin_word >> k;
    vector<string> bro_word;
    for (const auto &word: dict) {
        if (word == origin_word)
            continue;

        string copy1(word);
        string copy2(origin_word);
        sort(copy1.begin(), copy1.end());
        sort(copy2.begin(), copy2.end());
        if (copy1 == copy2)
            bro_word.push_back(word);
    }

    cout << bro_word.size() << endl;
    sort(bro_word.begin(), bro_word.end());
    if (k <= bro_word.size())
        cout << bro_word[k - 1];

    return 0;
}