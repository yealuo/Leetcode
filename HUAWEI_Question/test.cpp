#include <bits/stdc++.h>

using namespace std;

int main() {
    string t("1-2-3");
    stringstream ss(t);
    string temp;
    while (getline(ss, temp, '-')) {
        cout << temp << endl;
    }

    return 0;
}