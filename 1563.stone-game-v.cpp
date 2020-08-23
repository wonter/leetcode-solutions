/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
 */

// @lc code=start
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int dp[550][550] = {};
        int sum[550][550] = {};
        int n = stoneValue.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    sum[i][j] = stoneValue[i];
                } else {
                    sum[i][j] = sum[i][j - 1] + stoneValue[j];
                }
            }
        }

        for (int len = 2; len <= stoneValue.size(); ++len) {
            for (int s = 0; s < stoneValue.size(); ++s) {
                int e = s + len - 1;
                if (e >= stoneValue.size()) {
                    break;
                }

                for (int k = s; k < e; ++k) {
                    if (sum[s][k] == sum[k + 1][e]) {
                        dp[s][e] = max(dp[s][e], sum[s][k] + max(dp[s][k], dp[k + 1][e]));
                    } else if (sum[s][k] < sum[k + 1][e]) {
                        dp[s][e] = max(dp[s][e], sum[s][k] + dp[s][k]);
                    } else {
                        dp[s][e] = max(dp[s][e], sum[k + 1][e] + dp[k + 1][e]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

