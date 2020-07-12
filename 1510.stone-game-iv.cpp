/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[100050];
        fill(begin(dp), end(dp), false);
        
        dp[0] = false;
        for (long long i = 1; i <= n; ++i) {
            for (long long j = 1; j * j <= i; ++j) {
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
// @lc code=end

