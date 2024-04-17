//
// Created by Administrator on 2024/4/13.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<vector<string>> command{
        {"reset"},
        {"reset",     "board"},
        {"board",     "add"},
        {"board",     "delete"},
        {"reboot",    "backplane"},
        {"backplane", "abort"}
};

unordered_map<string, string> dict{
        {"reset",            "reset what"},
        {"reset board",      "board fault"},
        {"board add",        "where to add"},
        {"board delete",     "no board at all"},
        {"reboot backplane", "impossible"},
        {"backplane abort",  "install first"},
        {"u",                "unknown command"}
};

bool is_sub(const string &a, const string &b) {
    return a == b.substr(0, a.size());
}

int main() {
    string in;
    while (getline(cin, in)) {
        stringstream ss(in);
        string temp;
        vector<string> c;
        while (ss >> temp)
            c.emplace_back(temp);

        if (c.size() == 1) {
            if (is_sub(temp, command[0][0]))
                cout << dict[command[0][0]] << endl;
            else
                cout << dict["u"] << endl;
        } else if (c.size() == 2) {
            int count = 0;
            string result;
            for (int i = 1; i < command.size(); ++i) {
                if (is_sub(c[0], command[i][0]) && is_sub(c[1], command[i][1])) {
                    result = dict[command[i][0] + " " + command[i][1]];
                    ++count;
                }
            }
            
            if (count == 1)
                cout << result << endl;
            else
                cout << dict["u"] << endl;
        } else
            cout << dict["u"] << endl;
    }

    return 0;
}