/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret;
        int x = 0;
        int y = n;
        for (int i = 0; i < n; ++i) {
            ret.emplace_back(nums[x++]);
            ret.emplace_back(nums[y++]);
        }
        return ret;
    }
};
// @lc code=end

