/*
 * @lc app=leetcode id=1589 lang=cpp
 *
 * [1589] Maximum Sum Obtained of Any Permutation
 */

// @lc code=start
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();

        int counter[100500] = {};
        for (vector<int>& request : requests) {
            ++counter[request[0]];
            --counter[request[1] + 1];
        }

        for (int i = 1; i < n; ++i) {
            counter[i] += counter[i - 1];
        }

        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.emplace_back(counter[i]);
        }

        sort(tmp.begin(), tmp.end());
        sort(nums.begin(), nums.end());
        assert(tmp.size() == nums.size());

        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans = (ans + static_cast<long long>(tmp[i]) * nums[i]) % 1000000007;
        }
        return ans;
    }
};
// @lc code=end

