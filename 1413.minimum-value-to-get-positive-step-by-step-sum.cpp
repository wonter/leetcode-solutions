/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        int sum = 1;
        for (int num : nums) {
            sum -= num;
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

