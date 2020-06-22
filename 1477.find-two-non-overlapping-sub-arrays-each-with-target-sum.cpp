#include <bits/stdc++.h>
using namespace std;

// 
/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 */

// @lc code=start
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int dp[n + 1][2];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = 9999999;
            }
        }

        int prefix_sum = 0;
        unordered_map<int, int> prefix_sum_map = {{0, 0}};
        for (int i = 1; i <= n; ++i) {
            prefix_sum += arr[i - 1];

            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];

            auto it = prefix_sum_map.find(prefix_sum - target);
            if (it != prefix_sum_map.end()) {
                dp[i][0] = min(dp[i][0], i - it->second);
                dp[i][1] = min(dp[i][1], i - it->second + dp[it->second][0]);
            }

            prefix_sum_map[prefix_sum] = i;
        }

        return dp[n][1] == 9999999 ? -1 : dp[n][1];
    }
};
// @lc code=end

