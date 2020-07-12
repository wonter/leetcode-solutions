/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix_sum;
        
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum = (sum + nums[j]) % 1000000007;
                prefix_sum.emplace_back(sum);
            }
        }
        
        sort(prefix_sum.begin(), prefix_sum.end());
        
        left -= 1;
        right -= 1;
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            ret = (ret + prefix_sum[i]) % 1000000007;
        }
        return ret;
    }
};
// @lc code=end

