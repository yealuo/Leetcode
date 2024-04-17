//
// Created by Administrator on 2024/4/17.
//
#include <iostream>
#include <vector>

using namespace std;

bool is_access(int a1, int a2, const vector<int> &a) {
    if (a1 == a2 && a.empty())
        return true;
    else if (a1 != a2 && a.empty())
        return false;
    
    vector<int> a_copy(a);
    int num = a_copy[0];
    a_copy.erase(a_copy.begin());
    if (is_access(a1 + num, a2, a_copy) || is_access(a1, a2 + num, a_copy))
        return true;

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        if (temp % 5 == 0)
            a1 += temp;
        else if (temp % 3 == 0)
            a2 += temp;
        else
            a.emplace_back(temp);
    }

    if (is_access(a1, a2, a))
        cout << "true";
    else
        cout << "false";

    return 0;
}