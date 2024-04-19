#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> v(M), value(M);
    for (int i = 0; i < M; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> value[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (j < v[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[M][N];

    return 0;
}