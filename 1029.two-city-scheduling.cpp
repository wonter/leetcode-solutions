/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */
class Solution {
public:

    // solution 1
        // int twoCitySchedCost(vector<vector<int>>& costs) {
        //     int n = costs.size();
        //     int dp[n + 1][n + 1];
        //     memset(dp, 127, sizeof(dp));

        //     dp[0][0] = 0;
        //     for (int i = 1; i <= n; ++i) {
        //         for (int j = 0; j <= i; ++j) {
        //             if (j == 0) {
        //                 dp[i][j] = dp[i - 1][j] + costs[i - 1][1];
        //             } else {
        //                 dp[i][j] = min(dp[i - 1][j - 1] + costs[i - 1][0], dp[i - 1][j] + costs[i - 1][1]);
        //             }
        //         }
        //     }

        //     return dp[n][n / 2];
        // }

    // solution 2
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        };
        sort(costs.begin(), costs.end(), cmp);

        int n = costs.size();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n / 2) {
                total += costs[i][0];
            } else {
                total += costs[i][1];
            }
        }

        return total;
    }
};

