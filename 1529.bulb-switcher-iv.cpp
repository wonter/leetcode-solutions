/*
 * @lc app=leetcode id=1529 lang=cpp
 *
 * [1529] Bulb Switcher IV
 */

// @lc code=start
class Solution {
public:
    int minFlips(string target) {
        int ret = 0;

        int now = 0;
        for (char ch : target) {
            if (ch - '0' != now) {
                now ^= 1;
                ret += 1;
            }
        }

        return ret;
    }
};
// @lc code=end

