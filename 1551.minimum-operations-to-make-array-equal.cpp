/*
 * @lc app=leetcode id=1551 lang=cpp
 *
 * [1551] Minimum Operations to Make Array Equal
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (2 * i + 1 > n) {
                ans += 2 * i + 1 - n;
            }
        }
        return ans;
    }
};
// @lc code=end

