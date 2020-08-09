/*
 * @lc app=leetcode id=1546 lang=cpp
 *
 * [1546] Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
 */

// @lc code=start
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ret = 0;
        unordered_map<int, int> prefix_sum;

        prefix_sum[0] = -1;
        int sum = 0;
        int last_choose = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            auto it = prefix_sum.find(sum - target);
            if (it != prefix_sum.end() && it->second + 1 > last_choose) {
                last_choose = i;
                ++ret;
            }

            prefix_sum[sum] = i;
        }

        return ret;
    }
};
// @lc code=end

