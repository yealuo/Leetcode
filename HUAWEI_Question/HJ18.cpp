//
// Created by Administrator on 2024/4/2.
//
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool if_valid_ip(const string &ip) {
    int dot_num = 0;
    int prev = 0;
    for (int curt = 0; curt < ip.size(); ++curt) {
        if (ip[curt] == '.' || curt + 1 == ip.size()) {
            ++dot_num;
            if (curt + 1 == ip.size()) {
                ++curt;
                --dot_num;
            }

            string substr(ip.begin() + prev, ip.begin() + curt);
            if (substr.empty() || substr.size() > 3) {
                return false;
            } else if (substr.size() == 1) {
                prev = curt + 1;
            } else {
                if (substr[0] == '0') {
                    return false;
                }
                int num = stoi(substr);
                if (num > 255) {
                    return false;
                }
                prev = curt + 1;
            }
        }
    }

    if (dot_num != 3) {
        return false;
    }

    return true;
}

bool if_valid_mask(const string &mask) {
    if (mask[0] == '0') {
        return false;
    }

    int dot_num = 0;
    int prev = 0;
    bool flag = false;
    for (int curt = 0; curt < mask.size(); ++curt) {
        if (mask[curt] == '.' || curt + 1 == mask.size()) {
            ++dot_num;
            if (curt + 1 == mask.size()) {
                ++curt;
                --dot_num;
            }

            string substr(mask.begin() + prev, mask.begin() + curt);
            if (substr.empty() || substr.size() > 3) {
                return false;
            } else {
                if (mask.size() != 1 && mask[0] == '0') {
                    return false;
                }

                int num = stoi(substr);
                bitset<8> bin(num);
                for (int i = 7; i >= 0; --i) {
                    if (bin[i] == 0) {
                        flag = true;
                    }
                    if (bin[i] == 1 && flag) {
                        return false;
                    }
                }
                prev = curt + 1;
            }
        }
    }

    if (dot_num != 3) {
        return false;
    }
    if (!flag) {
        return false;
    }

    return true;
}

char judge_type(const string &ip) {
    int index = 0;
    while (ip[index] != '.') {
        ++index;
    }
    string substr(ip.begin(), ip.begin() + index);
    int num = stoi(substr);
    bitset<8> bin(num);

    if (bin[7] == 0) {
        return 'A';
    } else if (bin[7] == 1 && bin[6] == 0) {
        return 'B';
    } else if (bin[6] == 1 && bin[5] == 0) {
        return 'C';
    } else if (bin[5] == 1 && bin[4] == 0) {
        return 'D';
    } else if (bin[4] == 1) {
        return 'E';
    }
    return 'P';
}

bool if_private(const string &ip) {
    int index1 = 0;
    while (ip[index1] != '.') {
        ++index1;
    }
    string substr1(ip.begin(), ip.begin() + index1);

    int index2 = index1 + 1;
    while (ip[index2] != '.') {
        ++index2;
    }
    string substr2(ip.begin() + index1 + 1, ip.begin() + index2);

    if (substr1 == "10") {
        return true;
    } else if (substr1 == "192" && substr2 == "168") {
        return true;
    } else if (substr1 == "172") {
        int temp = stoi(substr2);
        if (temp >= 16 && temp <= 31) {
            return true;
        }
    }

    return false;
}

bool if_pass(const string &ip) {
    int index1 = 0;
    while (ip[index1] != '.') {
        ++index1;
    }
    string substr1(ip.begin(), ip.begin() + index1);

    if (substr1 == "127" || substr1 == "0") {
        return true;
    }

    return false;
}

int main() {
    vector<int> count(5, 0);
    int invalid_num = 0, private_num = 0;

    string line;
    while (cin >> line) {
        int index = 0;
        while (line[index] != '~') {
            ++index;
        }
        string ip(line.begin(), line.begin() + index);
        string mask(line.begin() + index + 1, line.end());

        if (if_pass(ip)) {
            continue;
        }

        if (!if_valid_ip(ip) || !if_valid_mask(mask)) {
            ++invalid_num;
            continue;
        }

        char type = judge_type(ip);
        ++count[type - 'A'];

        if (if_private(ip)) {
            ++private_num;
        }
    }

    for (const auto &num: count) {
        cout << num << " ";
    }

    cout << invalid_num << " " << private_num;

    return 0;
}
// 64 位输出请用 printf("%lld")
