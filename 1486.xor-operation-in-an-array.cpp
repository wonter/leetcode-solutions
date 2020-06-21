/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i = 1; i < n; ++i) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
};
// @lc code=end

