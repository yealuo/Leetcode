//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string p;
    cin >> p;

    int score = 0;
    if (p.size() <= 4)
        score += 5;
    else if (p.size() >= 5 && p.size() <= 7)
        score += 10;
    else
        score += 25;

    bool is_lower = false, is_upper = false;
    int digit_num = 0, sy_num = 0;
    for (const auto &elem: p) {
        if (islower(elem))
            is_lower = true;
        if (isupper(elem))
            is_upper = true;

        if (isdigit(elem))
            ++digit_num;

        if (!isalnum(elem))
            ++sy_num;
    }

    if ((is_lower && !is_upper) || (!is_lower && is_upper))
        score += 10;
    else if (is_lower && is_upper)
        score += 20;

    if (digit_num == 1)
        score += 10;
    else if (digit_num > 1)
        score += 20;

    if (sy_num == 1)
        score += 10;
    else if (sy_num > 1)
        score += 25;

    if ((is_upper && is_lower) && (digit_num != 0) && (sy_num != 0))
        score += 5;
    else if (((is_lower && !is_upper) || (!is_lower && is_upper)) && (digit_num != 0) && (sy_num != 0))
        score += 3;
    else if ((is_lower || is_upper) && (digit_num != 0) && (sy_num == 0))
        score += 2;

    if (score >= 90)
        cout << "VERY_SECURE";
    else if (score >= 80)
        cout << "SECURE";
    else if (score >= 70)
        cout << "VERY_STRONG";
    else if (score >= 60)
        cout << "STRONG";
    else if (score >= 50)
        cout << "AVERAGE";
    else if (score >= 25)
        cout << "WEAK";
    else
        cout << "VERY_WEAK";

    return 0;
}