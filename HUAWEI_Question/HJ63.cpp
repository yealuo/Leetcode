//
// Created by Administrator on 2024/4/12.
//
#include <iostream>

using namespace std;

double ratio(const string &str) {
    int size = str.size();
    double count = 0.0;
    for (const auto &alpha: str) {
        if (alpha == 'C' || alpha == 'G')
            ++count;
    }

    return count / size;
}

int main() {
    string DNA;
    int len;
    cin >> DNA >> len;

    double max_ratio = 0.0;
    string result;
    for (int i = 0; i <= DNA.size() - len; ++i) {
        string sub_dna = DNA.substr(i, len);
        if (ratio(sub_dna) > max_ratio) {
            max_ratio = ratio(sub_dna);
            result = sub_dna;
        }
    }

    cout << result;

    return 0;
}