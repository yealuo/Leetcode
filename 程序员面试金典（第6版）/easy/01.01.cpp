#include <iostream>
#include <string>
using namespace std;

bool isUnique_1(string astr) {
    if (astr.empty()) {
        return true;
    }
    if (astr.size() > 26) {
        return false;
    }
    for (int i = 0; i < astr.size(); i++) {
        for (int j = i + 1; j < astr.size(); j++) {
            if (astr[j] == astr[i]) {
                return false;
            }
        }
    }
    return true;
}

bool isUnique_2(string astr) {
    if (astr.empty()) {
        return true;
    }
    if (astr.size() > 26) {
        return false;
    }
    int result = 0;
    for (int i = 0; i < astr.size(); i++) {
        if (result & (1 << (astr[i] - 'a'))) {
            return false;
        } else {
            result |= (1 << (astr[i] - 'a'));
        }
    }
    return true;
}

int main() {
    return 0;
}