#include <iostream>
#include <string>
using namespace std;

bool isFlipedString(string s1, string s2) {
    return s1.size() == s2.size()&&(s2 + s2).find(s1) != string::npos;
}

int main() {
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << isFlipedString(s1, s2) << endl;
    return 0;
}
