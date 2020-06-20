#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k < 0) {
            k = -k;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0 && nums[i + 1] == 0) {
                return true;
            }
        }
        if (k == 0) {
            return false;
        }

        vector<long long> prefix_sum;
        unordered_set<int> vis;
        for (int num : nums) {
            if (prefix_sum.empty()) {
                prefix_sum.emplace_back(num);
            } else {
                prefix_sum.emplace_back(prefix_sum.back() + num);
            }

            if (prefix_sum.size() >= 2 && prefix_sum.back() % k == 0) {
                return true;
            }

            if (vis.find(prefix_sum.back() % k) != vis.end()) {
                return true;
            }

            if (prefix_sum.size() >= 2) {
                vis.insert(prefix_sum[prefix_sum.size() - 2] % k);
            }
        }

        return false;
    }
};
// @lc code=end

