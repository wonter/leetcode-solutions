/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        int dp[n][m + 1];
        memset(dp, 0x0f, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            dp[i][m] = 0;
        }

        for (int j = m - 1; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j] = INT_MAX;
                for (int clockwise_step = 0; clockwise_step < n; ++clockwise_step) {
                    if (ring[(i + clockwise_step) % n] == key[j]) {
                        dp[i][j] = min(dp[i][j], dp[(i + clockwise_step) % n][j + 1] + clockwise_step + 1);
                        dp[i][j] = min(dp[i][j], dp[(i + clockwise_step) % n][j + 1] + (n - clockwise_step) % n + 1);
                    }
                }
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
