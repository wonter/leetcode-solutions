/*
 * @lc app=leetcode id=1553 lang=cpp
 *
 * [1553] Minimum Number of Days to Eat N Oranges
 */

// @lc code=start
class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> dp;
        return minDays(n, dp);
    }

private:
    int minDays(int n, unordered_map<int, int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        auto it = dp.find(n);
        if (it != dp.end()) {
            return it->second;
        }

        dp[n] = 1 + min(n % 2 + minDays(n / 2, dp), n % 3 + minDays(n / 3, dp));
        return dp[n];
    }
};
// @lc code=end

