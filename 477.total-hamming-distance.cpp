/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int zero = 0;
            int one = 0;
            for (int num : nums) {
                if (num & (1u << i)) {
                    ++one;
                } else {
                    ++zero;
                }
            }
            ans += one * zero;
        }
        return ans;
    }
};
// @lc code=end

