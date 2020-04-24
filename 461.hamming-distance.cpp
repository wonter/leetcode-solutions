/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int ret = 0;
        while (n != 0) {
            if (n & 1) {
                ++ret;
            }
            n >>= 1;
        }
        return ret;
    }
};
// @lc code=end

