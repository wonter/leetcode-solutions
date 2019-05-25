/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};

