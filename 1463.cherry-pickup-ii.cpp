/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[100][100][100] = { 0 };

        int n = grid.size();
        int m = grid[0].size();

        for (int i = n - 1; i >= 0; --i) {
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = 0; j2 < m; ++j2) {
                    for (int k1 = 0; k1 < 3; ++k1) {
                        int next_j1 = j1 + dy[k1];
                        if (next_j1 < 0 || next_j1 >= m) {
                            continue;
                        }

                        for (int k2 = 0; k2 < 3; ++k2) {
                            int next_j2 = j2 + dy[k2];
                            if (next_j2 < 0 || next_j2 >= m) {
                                continue;
                            }

                            int weight = 0;
                            if (j1 == j2) {
                                weight = grid[i][j1];
                            } else {
                                weight = grid[i][j1] + grid[i][j2];
                            }

                            dp[i][j1][j2] = max(dp[i][j1][j2], weight + dp[i + 1][next_j1][next_j2]);
                        }
                    }
                }
            }
        }

        return dp[0][0][m - 1];
    }

private:
    int dy[3] = {-1, 0, 1};
};
// @lc code=end

