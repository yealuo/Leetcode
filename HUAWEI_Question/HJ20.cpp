//
// Created by Administrator on 2024/4/3.
//
#include <iostream>

using namespace std;

bool is_type_valid(const string &str) {
    int capital_flag = 0, lower_flag = 0, digit_flag = 0, other_flag = 0;

    for (const auto &member: str) {
        if (isupper(member))
            capital_flag = 1;
        else if (islower(member))
            lower_flag = 1;
        else if (isdigit(member))
            digit_flag = 1;
        else
            other_flag = 1;
    }

    if (capital_flag + lower_flag + digit_flag + other_flag < 3) {
        return false;
    } else {
        return true;
    }
}

bool is_substr_valid(const string &str) {
    for (int i = 0; i < str.size() - 1; ++i) {
        for (int j = i + 1; j <= str.size(); ++j) {
            if (j - i < 3)
                continue;

            string substr(str.begin() + i, str.begin() + j);
            if (str.substr(i + 1).find(substr) != string::npos) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string password;

    while (cin >> password) {
        if (password.size() <= 8 || !is_type_valid(password) || !is_substr_valid(password)) {
            cout << "NG" << endl;
        } else {
            cout << "OK" << endl;
        }
    }

    return 0;
}