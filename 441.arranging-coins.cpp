/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int need = 1;
        int ret = 0;
        while (n >= need) {
            n -= need;
            need += 1;
            ret += 1;
        }
        return ret;
    }
};
// @lc code=end

