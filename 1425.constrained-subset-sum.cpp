/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subset Sum
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int dp[nums.size()];
        priority_queue<pair<int, int>> que;
        int n = nums.size();
        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            while (!que.empty() && (i - que.top().second) > k) {
                que.pop();
            }

            if (que.empty()) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(nums[i], que.top().first + nums[i]);
            }

            que.push({dp[i], i});
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

