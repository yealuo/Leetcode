//
// Created by Administrator on 2024/4/16.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dict{
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'1', 10},
        {'J', 11},
        {'Q', 12},
        {'K', 13},
        {'A', 1}
};

string path;

bool dfs(const vector<string> &cards, double result) {
    if (result == 24 && cards.empty())
        return true;
    else if (result != 24 && cards.empty())
        return false;

    for (int i = 0; i < cards.size(); ++i) {
        vector<string> copy(cards);
        int num = dict[copy[i][0]];
        string card = copy[i];
        copy.erase(copy.begin() + i);

        if (dfs(copy, result + num)) {
            path = "+" + card + path;
            return true;
        } else if (dfs(copy, result - num)) {
            path = "-" + card + path;
            return true;
        } else if (dfs(copy, result * num)) {
            path = "*" + card + path;
            return true;
        } else if (dfs(copy, result / num)) {
            path = "/" + card + path;
            return true;
        }
    }

    return false;
}

int main() {
    vector<string> cards(4);
    string temp;
    for (int i = 0; i < 4; ++i) {
        cin >> temp;
        if (temp == "joker" || temp == "Joker") {
            cout << "ERROR";
            return 0;
        }
        cards[i] = temp;
    }

    for (int i = 0; i < cards.size(); ++i) {
        vector<string> copy(cards);
        int num = dict[copy[i][0]];
        copy.erase(copy.begin() + i);

        if (dfs(copy, num)) {
            path = cards[i] + path;
            cout << path;
            return 0;
        }
    }

    cout << "NONE";
    return 0;
}