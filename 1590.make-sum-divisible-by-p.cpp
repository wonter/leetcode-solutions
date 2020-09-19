/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        int ret = n;

        int sum = 0;
        unordered_map<int, vector<int>> suffix_sum;
        for (int i = n - 1; i >= 0; --i) {
            sum = (sum + nums[i]) % p;
            suffix_sum[sum].emplace_back(i);
            if (sum == 0) {
                ret = min(ret, i);
            }
        }

        for (auto& it : suffix_sum) {
            sort(it.second.begin(), it.second.end());
        }

        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % p;
            if (sum == 0) {
                ret = min(ret, n - i - 1);
            }

            int need = p - sum;
            auto it = suffix_sum.find(need);
            if (it == suffix_sum.end()) {
                continue;
            }

            const vector<int>& indexed = it->second;
            auto tmp = upper_bound(indexed.begin(), indexed.end(), i);
            if (tmp == indexed.end()) {
                continue;
            }

            int need_index = *tmp;
            ret = min(ret, n - (i + 1) - (n - need_index));
        }

        if (ret == n) {
            return -1;
        }

        return ret;
    }
};
// @lc code=end

