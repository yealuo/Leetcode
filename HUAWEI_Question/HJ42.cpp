//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//字典
vector<string> dict1{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> dict2{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                     "nineteen"};
vector<string> dict3{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//将反转后的字符串数字转换为英文
string process1(string &num_str) {
    string result;
    //统一为三位数
    if (num_str.size() == 1)
        num_str += "00";
    else if (num_str.size() == 2)
        num_str += "0";

    if (num_str[1] != '1') {    //十位数不为1可直接组合处理
        result += dict1[num_str[0] - '0'];
        if (num_str[1] != '0') {
            if (!result.empty())
                result = dict3[num_str[1] - '0'] + " " + result;
            else    //个位数为0不添加空格
                result = dict3[num_str[1] - '0'];
        }
    } else  //十位数为1需要单独处理
        result += dict2[num_str[0] - '0'];

    if (num_str[2] != '0') {
        if (!result.empty())
            result = dict1[num_str[2] - '0'] + " hundred and " + result;
        else
            result = dict1[num_str[2] - '0'] + " hundred";
    }

    return result;
}

int main() {
    string in;
    cin >> in;
    vector<string> num;
    reverse(in.begin(), in.end());  //反转以便划分
    for (int i = 0; i < in.size(); i += 3) {    //每三位一组划分
        string sub_str = in.substr(i, 3);
        sub_str = process1(sub_str);
        num.push_back(sub_str);
    }

    string result;
    for (int i = 0; i < num.size(); ++i) {
        if (i == 3 && !num[i].empty())
            result = num[i] + " billion " + result;
        else if (i == 2 && !num[i].empty())
            result = num[i] + " million " + result;
        else if (i == 1 && !num[i].empty())
            result = num[i] + " thousand " + result;
        else
            result += num[i];
    }

    cout << result;

    return 0;
}