/*
 * @lc app=leetcode id=1537 lang=cpp
 *
 * [1537] Get the Maximum Score
 */

// @lc code=start
long long dp[2][100050] = {};
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        unordered_map<int, int> num_idx[2];

        for (int i = 0; i < nums1.size(); ++i) {
            num_idx[0][nums1[i]] = i;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            num_idx[1][nums2[i]] = i;
        }

        return max(dfs(0, 0, nums1, nums2, num_idx), dfs(1, 0, nums1, nums2, num_idx)) % 1000000007;
    }

private:
    long long dfs(int which, int pos, const vector<int>& nums1, const vector<int>& nums2, unordered_map<int, int> num_idx[2]) {
        if (which == 0 && pos >= nums1.size()) {
            return 0;
        }
        if (which == 1 && pos >= nums2.size()) {
            return 0;
        }
        if (dp[which][pos] != -1) {
            return dp[which][pos];
        }

        int num = which == 0 ? nums1[pos] : nums2[pos];
        auto other_pos = num_idx[which^1].find(num);

        dp[which][pos] = num + dfs(which, pos + 1, nums1, nums2, num_idx);
        if (other_pos != num_idx[which^1].end()) {
            dp[which][pos] = max(dp[which][pos], num + dfs(which^1, other_pos->second + 1, nums1, nums2, num_idx));
        }

        return dp[which][pos];
    }
};
// @lc code=end
