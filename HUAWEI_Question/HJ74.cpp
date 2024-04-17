//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    in += " ";    //方便截取

    vector<string> parameters;
    int prev = 0;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == '\"') {
            do {
                ++i;
            } while (in[i] != '\"');
            parameters.emplace_back(in.begin() + prev + 1, in.begin() + i);
            prev = i + 2;
            i = i + 1;
        } else {
            while (!isspace(in[i]))
                ++i;
            parameters.emplace_back(in.begin() + prev, in.begin() + i);
            prev = i + 1;
        }
    }

    cout << parameters.size() << endl;
    for (const auto &para: parameters)
        cout << para << endl;

    return 0;
}