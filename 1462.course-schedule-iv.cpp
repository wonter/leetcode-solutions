/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool dp[100][100] = { };

        for (const vector<int>& vec : prerequisites) {
            dp[vec[0]][vec[1]] = true;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] |= dp[i][k] & dp[k][j];
                }
            }
        }

        vector<bool> ret;
        for (const vector<int>& query : queries) {
            ret.emplace_back(dp[query[0]][query[1]]);
        }
        return std::move(ret);
    }
};
// @lc code=end

