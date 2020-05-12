/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        long long pre = 1;
        long long cur = 1;
        for (int i = 1; i < n; ++i) {
            long long combine = (i * 2) * (i * 2 + 1) / 2;
            long long gap = i * 2 + 1;
            cur = pre * (combine + gap) % 1000000007;
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

