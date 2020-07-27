/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        return odd(high) - odd(low - 1);
    }

private:
    int odd(int x) {
        return (x + 1) / 2;
    }
};
// @lc code=end

