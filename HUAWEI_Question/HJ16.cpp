//
// Created by Administrator on 2024/4/2.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    N /= 10;
    int v, p, q;
    vector<vector<int>> prices(m + 1, vector<int>(3, 0));
    vector<vector<int>> satisfaction(m + 1, vector<int>(3, 0));
    for (int i = 1; i <= m; ++i) {
        cin >> v >> p >> q;
        if (q == 0) {
            prices[i][0] = v / 10;
            satisfaction[i][0] = v * p;
        } else {
            if (prices[q][1] == 0) {
                prices[q][1] = v / 10;
                satisfaction[q][1] = v * p;
            } else {
                prices[q][2] = v / 10;
                satisfaction[q][2] = v * p;
            }
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= N; ++j) {
            int no_attachment_price = prices[i][0], no_attachment_satis = satisfaction[i][0];
            int first_attachment_price = prices[i][1], first_attachment_satis = satisfaction[i][1];
            int second_attachment_price = prices[i][2], second_attachment_satis = satisfaction[i][2];

            dp[i][j] = j < no_attachment_price ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - no_attachment_price] +
                                                                                  no_attachment_satis);
            dp[i][j] = j < (no_attachment_price + first_attachment_price) ? dp[i][j] : max(dp[i][j],
                                                                                           dp[i - 1][j -
                                                                                                     no_attachment_price -
                                                                                                     first_attachment_price] +
                                                                                           no_attachment_satis +
                                                                                           first_attachment_satis);
            dp[i][j] = j < (no_attachment_price + second_attachment_price) ? dp[i][j] : max(dp[i][j],
                                                                                            dp[i - 1][j -
                                                                                                      no_attachment_price -
                                                                                                      second_attachment_price] +
                                                                                            no_attachment_satis +
                                                                                            second_attachment_satis);
            dp[i][j] = j < (no_attachment_price + first_attachment_price + second_attachment_price) ? dp[i][j] : max(
                    dp[i][j],
                    dp[i - 1][j -
                              no_attachment_price -
                              first_attachment_price -
                              second_attachment_price] +
                    no_attachment_satis +
                    first_attachment_satis +
                    second_attachment_satis);
        }
    }

    cout << dp[m][N];

    return 0;
}
