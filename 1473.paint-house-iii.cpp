/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[110][30][110];
        memset(dp, 64, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            dp[0][i][0] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (houses[i - 1] != 0 && j != houses[i - 1]) {
                    continue;
                }
                for (int k = 1; k <= i; ++k) {
                    for (int l = 1; l <= n; ++l) {
                        int cost_i = 0;
                        if (houses[i - 1] == 0) {
                            cost_i = cost[i - 1][j - 1];
                        }

                        if (j == l) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k] + cost_i);
                        } else {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k - 1] + cost_i);
                        }
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ret = min(ret, dp[m][i][target]);
        }
        if (ret > 10000000) {
            ret = -1;
        }
        return ret;
    }
};
// @lc code=end

