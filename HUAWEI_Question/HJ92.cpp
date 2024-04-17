//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string in;
    vector<string> max;
    int max_len;
    while (cin >> in) {
        max.clear();
        max_len = 0;
        int prev = 0;
        for (int i = 0; i < in.size(); ++i) {
            if (isdigit(in[i])) {
                prev = i;
                while (isdigit(in[i]) && i < in.size())
                    ++i;
                string sub_str(in.substr(prev, i - prev));
                if (sub_str.size() > max_len) {
                    max_len = sub_str.size();
                    max.clear();
                    max.emplace_back(sub_str);
                } else if (sub_str.size() == max_len)
                    max.emplace_back(sub_str);
            }
        }

        for (const auto &elem: max)
            cout << elem;

        cout << "," << max[0].size() << endl;
    }

    return 0;
}