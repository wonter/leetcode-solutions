/*
 * @lc app=leetcode id=1621 lang=cpp
 *
 * [1621] Number of Sets of K Non-Overlapping Line Segments
 */

// @lc code=start
class Solution {
public:
    Solution() {
        for (int i = 0; i <= 1000; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= 1000; ++j) {
            int sum = 0;
            for (int i = 1; i <= 1000; ++i) {
                sum = (sum + dp[i - 1][j - 1]) % 1000000007;
                dp[i][j] = (dp[i - 1][j] + sum) % 1000000007;
            }
        }
    }

    int numberOfSets(int n, int k) {
        return dp[n - 1][k];
    }

private:
    int dp[1010][1010]{0};
};
// @lc code=end

