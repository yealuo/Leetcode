//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class sys {
private:
    const vector<int> goods_price{2, 3, 4, 5, 8, 6};
    vector<int> goods_num;
    vector<int> amount;
    int m;

public:
    sys() : goods_num(6, 0), amount(4, 0), m(0) {}

    void init(const string &command) {
        string str;
        stringstream ss(command);

        ss >> str;   //去掉r

        ss >> str;   //读取商品初始化命令
        stringstream ss1(str);
        string num_str;
        for (int i = 0; i < 6; ++i) {
            getline(ss1, num_str, '-');
            goods_num[i] = stoi(num_str);
        }

        ss >> str;  //读取钱币初始化指令
        stringstream ss2(str);
        for (int i = 0; i < 4; ++i) {
            getline(ss2, num_str, '-');
            amount[i] = stoi(num_str);
        }

        cout << "S001:Initialization is successful" << endl;
    }

    void insert(const string &command) {
        string str;
        stringstream ss(command);

        ss >> str;    //去掉p

        int money;
        ss >> money;

        if (money != 1 && money != 2 && money != 5 && money != 10) {
            cout << "E002:Denomination error" << endl;
            return;
        } else if (amount[0] + amount[1] * 2 < money && money != 1 && money != 2) {
            cout << "E003:Change is not enough, pay fail" << endl;
            return;
        } else {
            int flag = false;
            for (const auto &elem: goods_num) {
                if (elem != 0) {
                    flag = true;
                }
            }

            if (!flag) {  //商品全部售空
                cout << "E005:All the goods sold out" << endl;
                return;
            } else {
                if (money == 1) {
                    ++amount[0];
                    m += money;
                } else if (money == 2) {
                    ++amount[1];
                    m += money;
                } else if (money == 5) {
                    ++amount[2];
                    m += money;
                } else {
                    ++amount[3];
                    m += money;
                }

                cout << "S002:Pay success,balance=" << m << endl;
            }
        }
    }

    void buy(const string &command) {
        string str;
        stringstream ss(command);

        ss >> str;    //去掉b

        ss >> str;
        if (str != "A1" && str != "A2" && str != "A3" && str != "A4" && str != "A5" && str != "A6") {
            cout << "E006:Goods does not exist" << endl;
            return;
        } else if (goods_num[str[1] - '0' - 1] == 0) {
            cout << "E007:The goods sold out" << endl;
            return;
        } else if (m < goods_price[str[1] - '0' - 1]) {
            cout << "E008:Lack of balance" << endl;
            return;
        } else {
            --goods_num[str[1] - '0' - 1];
            m -= goods_price[str[1] - '0' - 1];
            cout << "S003:Buy success,balance=" << m << endl;
            return;
        }
    }

    void refund() {
        if (m == 0) {
            cout << "E009:Work failure" << endl;
            return;
        }

        //退币
        vector<int> count(4, 0); //记录每种钱币退币数量
        while (m != 0) {
            if (m >= 10 && amount[3] != 0) {
                --amount[3];
                ++count[3];
                m -= 10;
            } else if (m >= 5 && amount[2] != 0) {
                --amount[2];
                ++count[2];
                m -= 5;
            } else if (m >= 2 && amount[1] != 0) {
                --amount[1];
                ++count[1];
                m -= 2;
            } else if (m >= 1 && amount[0] != 0) {
                --amount[0];
                ++count[0];
                m -= 1;
            } else {  //余额不足
                m = 0;
            }
        }

        cout << "1 yuan coin number=" << count[0] << endl;
        cout << "2 yuan coin number=" << count[1] << endl;
        cout << "5 yuan coin number=" << count[2] << endl;
        cout << "10 yuan coin number=" << count[3] << endl;
    }

    void enquiry(const string &command) {
        if (command.size() < 3) {
            cout << "E010:Parameter error" << endl;
            return;
        }

        string str;
        stringstream ss(command);

        ss >> str;    //去掉b

        int type;
        ss >> type;
        if (type == 0) {
            vector<pair<string, int>> num;
            for (int i = 0; i < 6; ++i) {
                num.emplace_back("A" + to_string(i + 1), goods_num[i]);
            }

            sort(num.begin(), num.end(), [](const pair<string, int> &a1, const pair<string, int> &a2) {
                if (a1.second == a2.second)
                    return a1.first < a2.first;
                else
                    return a1.second > a2.second;
            });

            for (const auto &elem: num) {
                cout << elem.first << " " << goods_price[elem.first[1] - '0' - 1] << " " << elem.second << endl;
            }
        } else if (type == 1) {
            cout << "1 yuan coin number=" << amount[0] << endl;
            cout << "2 yuan coin number=" << amount[1] << endl;
            cout << "5 yuan coin number=" << amount[2] << endl;
            cout << "10 yuan coin number=" << amount[3] << endl;
        } else {
            cout << "E010:Parameter error" << endl;
            return;
        }
    }

};

int main() {
    sys system;
    string command;
    while (getline(cin, command, ';')) {
        if (command[0] == 'r')
            system.init(command);
        else if (command[0] == 'p')
            system.insert(command);
        else if (command[0] == 'b')
            system.buy(command);
        else if (command[0] == 'c')
            system.refund();
        else if (command[0] == 'q')
            system.enquiry(command);
    }

    return 0;
}