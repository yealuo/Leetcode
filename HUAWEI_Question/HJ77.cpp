//
// Created by Administrator on 2024/4/15.
//
#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> result;

void back_tracking(const vector<int> &wait, const vector<int> &station, const vector<int> &path) {
    if (wait.empty() && station.empty()) {
        result.insert(path);
        return;
    }

    //进站
    if (!wait.empty()) {
        vector<int> temp_station(station);
        temp_station.emplace_back(wait[0]);
        back_tracking(vector<int>(wait.begin() + 1, wait.end()), temp_station, path);
    }

    //出站
    if (!station.empty()) {
        vector<int> temp_path(path);
        temp_path.emplace_back(station[station.size() - 1]);
        back_tracking(wait, vector<int>(station.begin(), station.end() - 1), temp_path);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> wait(n);
    for (int i = 0; i < n; ++i)
        cin >> wait[i];

    vector<int> station, path;

    back_tracking(wait, station, path);

    for (const auto &p: result) {
        for (const auto &train: p) {
            cout << train << " ";
        }
        cout << endl;
    }

    return 0;
}