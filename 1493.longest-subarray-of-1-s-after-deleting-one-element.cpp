/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_prefix[n + 2];
        int max_suffix[n + 2];
        fill(max_prefix, max_prefix + n + 2, 0);
        fill(max_suffix, max_suffix + n + 2, 0);

        max_prefix[0] = max_prefix[n + 1] = 0;
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] == 0) {
                max_prefix[i] = 0;
            } else {
                max_prefix[i] = max_prefix[i - 1] + 1;
            }
        }

        max_suffix[0] = max_suffix[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            if (nums[i - 1] == 0) {
                max_suffix[i] = 0;
            } else {
                max_suffix[i] = max_suffix[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, max_prefix[i - 1] + max_suffix[i + 1]);
        }
        return ans;
    }
};
// @lc code=end

