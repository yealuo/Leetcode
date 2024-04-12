//
// Created by Administrator on 2024/4/11.
//
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

unordered_map<char, int> op_priority{
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
};

void calculate(stack<char> &op, stack<int> &num) {
    int num2 = num.top();
    num.pop();
    int num1 = num.top();
    num.pop();
    char o = op.top();
    op.pop();

    switch (o) {
        case '+':
            num.push(num1 + num2);
            break;
        case '-':
            num.push(num1 - num2);
            break;
        case '*':
            num.push(num1 * num2);
            break;
        case '/':
            num.push(num1 / num2);
            break;
        default:
            break;
    }
}

int main() {
    string exp;
    cin >> exp;

    //在左右两侧都加上括号
    exp = "(" + exp + ")";

    stack<char> op;
    stack<int> num;

    bool flag = false; //是否遇到符号
    for (int i = 0; i < exp.size(); ++i) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            op.push('(');
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            while (op.top() != '(')
                calculate(op, num);
            op.pop();   //将左括号弹出
        } else if (flag) {  //运算符
            if (op_priority[exp[i]] > op_priority[op.top()])
                op.push(exp[i]);
            else {
                while (op_priority[exp[i]] <= op_priority[op.top()])
                    calculate(op, num);
                op.push(exp[i]);
            }
            flag = false;    //当前位不是左右括号，那么下一个一定是数字
        } else {
            int prev = i;
            if (exp[i] == '-')
                ++i;
            while (isdigit(exp[i]))
                ++i;
            num.push(stoi(exp.substr(prev, i - prev)));
            --i;
            flag = true; //下一个一定是符号
        }
    }

    cout << num.top();

    return 0;
}