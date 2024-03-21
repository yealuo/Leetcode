#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack1 {
   public:
    int min;
    vector<int> stack;
    vector<int> minNum;
    /** initialize your data structure here. */
    MinStack1() : min(INT_MAX) {}

    void push(int x) {
        stack.push_back(x);
        min = min < x ? min : x;
        minNum.push_back(min);
    }

    void pop() {
        stack.pop_back();
        minNum.pop_back();
        if (stack.empty()) {
            min = INT_MAX;
        } else {
            min = minNum.back();
        }
    }

    int top() { return stack.back(); }

    int getMin() { return minNum.back(); }
};

class MinStack {
   public:
    int min;
    stack<int> myStack;
    stack<int> minNum;
    /** initialize your data structure here. */
    MinStack() : min(INT_MAX) {}

    void push(int x) {
        myStack.push(x);
        min = min < x ? min : x;
        minNum.push(min);
    }

    void pop() {
        myStack.pop();
        minNum.pop();
        if (myStack.empty()) {
            min = INT_MAX;
        } else {
            min = minNum.top();
        }
    }

    int top() { return myStack.top(); }

    int getMin() { return minNum.top(); }
};

int main() {
    return 0;
}