//
// Created by Administrator on 2024/4/3.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
    string path;
    string line_num;
    unordered_map<string, int> files;
    deque<string> file_seq;
    while (cin >> path >> line_num) {
        string file_name = path.substr(path.find_last_of('\\') + 1);
        string key;
        if (file_name.size() <= 16)
            key = file_name + " " + line_num;
        else
            key = file_name.substr(file_name.size() - 16) + " " + line_num;

        if (files.find(key) == files.end()) {
            file_seq.push_back(key);
        }
        ++files[key];

        if (file_seq.size() > 8) {
            file_seq.pop_front();
        }
    }

    for (const auto &file: file_seq) {
        cout << file << " " << files[file] << endl;
    }

    return 0;
}