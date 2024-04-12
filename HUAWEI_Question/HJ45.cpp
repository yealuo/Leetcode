//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<string> str(count);
    for (int i = 0; i < count; ++i) {
        string temp;
        cin >> temp;

        vector<int> alpha_count(26, 0);
        for (const auto &alpha: temp)
            ++alpha_count[alpha - 'a'];

        sort(alpha_count.rbegin(), alpha_count.rend());

        int result = 0;
        for (int j = 0; j < 26; ++j)
            result += alpha_count[j] * (26 - j);

        cout << result << endl;
    }

    return 0;
}