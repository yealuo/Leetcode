//
// Created by Administrator on 2024/4/10.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string key, str;
    getline(cin, key);
    getline(cin, str);

    //去重
    vector<char> key_alpha;
    for (const auto &alpha: key) {
        char copy = tolower(alpha);
        if (find(key_alpha.begin(), key_alpha.end(), copy) == key_alpha.end())
            key_alpha.push_back(copy);
    }

    string alphabet("abcdefghijklmnopqrstuvwxyz");
    int i = 0;
    for (const auto &alpha: key_alpha) {
        alphabet.erase(alphabet.find(alpha), 1);
        alphabet.insert(i++, 1, alpha);
    }

    for (auto &alpha: str) {
        if (isalpha(alpha)) {
            if (isupper(alpha))
                alpha = toupper(alphabet[alpha - 'A']);
            else
                alpha = alphabet[alpha - 'a'];
        }
    }
    cout << str;

    return 0;
}