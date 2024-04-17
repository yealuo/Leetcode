//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a1, a2;
    while (scanf("%d/%d", &a1, &a2) != EOF) {
        string result;
        for (int i = 1; i <= a1; ++i)
            result += "1/" + to_string(a2) + "+";

        result.pop_back();

        cout << result << endl;
    }

    return 0;
}