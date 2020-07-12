/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= 3; ++i) {
            int remove_head = i;
            int remove_tail = 3 - i;
            ans = min(ans, nums[nums.size() - 1 - remove_tail] - nums[remove_head]);
        }
        return ans;
    }
};
// @lc code=end

