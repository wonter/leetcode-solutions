/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        power[0] = 1;
        for (int i = 1; i <= 100000; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int max_maxnum = target - nums[i];
            int maxnum_idx = upper_bound(nums.begin() + i, nums.end(), max_maxnum) - nums.begin() - 1;
            if (maxnum_idx < i) {
                continue;
            }

            assert(maxnum_idx >= i);

            ret = (ret + power[maxnum_idx - i]) % MOD;
        }
        return ret;
    }

private:
    int power[100105];
    const int MOD = 1000000007;
};
// @lc code=end

