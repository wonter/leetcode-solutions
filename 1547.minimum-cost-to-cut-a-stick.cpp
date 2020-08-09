/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());

        vector<int> lens;
        for (size_t i = 1; i < cuts.size(); ++i) {
            lens.emplace_back(cuts[i] - cuts[i - 1]);
        }
        n = lens.size();

        int sum[200][200] = {};
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    sum[i][j] = lens[j];
                } else {
                    sum[i][j] = sum[i][j - 1] + lens[j];
                }
            }
        }

        int dp[200][200];
        memset(dp, 63, sizeof(dp));
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l < n; ++l) {
                int r = l + len - 1;
                if (r >= n) {
                    break;
                }

                for (int k = l + 1; k <= r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k][r] + sum[l][r]);
                }

                if (len == 1) {
                    dp[l][r] = 0;
                }
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end
