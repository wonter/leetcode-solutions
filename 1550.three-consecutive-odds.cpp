/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter = 0;
        for (int num : arr) {
            if (num & 1) {
                ++counter;
            } else {
                counter = 0;
            }

            if (counter == 3) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

