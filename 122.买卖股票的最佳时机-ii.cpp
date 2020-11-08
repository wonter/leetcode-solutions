/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> dp(prices.size(), 0);
        int tmp = -prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            dp[i] = max(dp[i - 1], tmp + prices[i]);
            tmp = max(tmp, dp[i - 1] - prices[i]);
        }
        return dp.back();
    }
};
// @lc code=end

