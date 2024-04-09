//
// Created by Administrator on 2024/4/8.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void merge_sort(string &str, size_t left, size_t right) {
    if (left == right)
        return;

    size_t mid = left + ((right - left) >> 1);
    merge_sort(str, left, mid);
    merge_sort(str, mid + 1, right);

    string temp;
    size_t l = left, r = mid + 1;
    while (l <= mid && r <= right) {
        temp += tolower(str[l]) <= tolower(str[r]) ? str[l++] : str[r++];
    }
    if (r > right) {
        while (l <= mid)
            temp += str[l++];
    } else {
        while (r <= right)
            temp += str[r++];
    }

    for (int i = 0; i < temp.size(); ++i) {
        str[i + left] = temp[i];
    }
}

int main_method1() {
    string in, temp;
    getline(cin, in);
    for (char i: in) {
        if (isalpha(i))
            temp += i;
    }
    merge_sort(temp, 0, temp.size() - 1);
    for (int i = 0; i < in.size(); ++i) {
        if (!isalpha(in[i]))
            temp.insert(i, 1, in[i]);
    }
    cout << temp;

    return 0;
}

int main() {
    string in, temp;
    getline(cin, in);
    for (int i = 0; i < 26; ++i) {
        for (const auto &alpha: in) {
            if (alpha - 'a' == i || alpha - 'A' == i)
                temp += alpha;
        }
    }
    int index = 0;
    for (auto &alpha: in) {
        if (isalpha(alpha))
            alpha = temp[index++];
    }
    cout << in;

    return 0;
}


