//
// Created by Administrator on 2024/4/12.
//
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> priority{
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
};

void calculate(stack<int> &num, stack<char> &op) {
    int num2 = num.top();
    num.pop();
    int num1 = num.top();
    num.pop();
    char o = op.top();
    op.pop();

    int result;

    switch (o) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            break;
    }

    num.push(result);
}

int main() {
    string exp;
    cin >> exp;
    exp = "(" + exp + ")";    //给表达式左右加上括号以便表达式输入结束自动计算

    stack<int> num;
    stack<char> op;
    bool flag = false;
    for (int i = 0; i < exp.size(); ++i) {
        if (exp[i] == '(')
            op.push('(');
        else if (exp[i] == ')') {
            while (op.top() != '(')
                calculate(num, op);
            op.pop();   //左括号弹出
        } else if (flag) {
            if (priority[exp[i]] > priority[op.top()])
                op.push(exp[i]);
            else {
                while (priority[exp[i]] <= priority[op.top()])
                    calculate(num, op);
                op.push(exp[i]);
            }
            flag = false;    //下一个不是括号就是数
        } else {
            int index = i;
            if (exp[i] == '-') //负数
                ++i;
            while (isdigit(exp[i]))
                ++i;
            string num_str = exp.substr(index, i - index);
            num.push(stoi(num_str));
            --i;    //for循环i会自增，这里使i指向最后一个数字
            flag = true;  //下一个一定是符号
        }
    }

    cout << num.top();

    return 0;
}