#include <iostream>
#include <vector>
using namespace std;

class TripleInOne {
   public:
    vector<int> array;
    vector<int> stackTop;
    int stackLength;
    TripleInOne(int stackSize) : stackLength(stackSize) {
        int arraySize = stackLength * 3;
        array.assign(arraySize, 0);
        stackTop.assign(3, 0);
        stackTop[0] = 0;
        stackTop[1] = stackSize;
        stackTop[2] = stackSize * 2;
    }

    void push(int stackNum, int value) {
        if (stackTop[stackNum] == (stackNum + 1) * stackLength) {
            return;
        }
        array[stackTop[stackNum]] = value;
        ++stackTop[stackNum];
    }

    int pop(int stackNum) {
        if (stackTop[stackNum] == stackNum * stackLength) {
            return -1;
        }
        int result;
        result = array[stackTop[stackNum] - 1];
        --stackTop[stackNum];
        return result;
    }

    int peek(int stackNum) {
        if (stackTop[stackNum] == stackNum * stackLength) {
            return -1;
        }
        return array[stackTop[stackNum] - 1];
    }

    bool isEmpty(int stackNum) {
        if (stackTop[stackNum] == stackNum * stackLength) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    return 0;
}