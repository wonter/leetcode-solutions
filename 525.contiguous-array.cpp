/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum[n + 1];
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (nums[i - 1] == 0 ? 1 : 0);
        }

        unordered_map<int, int> sum_idx;
        int maxlen = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp = 2 * sum[i] - i;
            auto it = sum_idx.find(tmp);
            if (it != sum_idx.end()) {
                maxlen = max(maxlen, i - it->second + 1);
            }

            tmp = 2 * sum[i - 1] - (i - 1);
            if (sum_idx.find(tmp) == sum_idx.end()) {
                sum_idx[tmp] = i;
            }
        }
        return maxlen;
    }
};
// @lc code=end

