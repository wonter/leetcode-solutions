/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 */

// @lc code=start
long long dp[1010][1010];
long long has[1010][26];
const long long MOD = 1000000007;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        memset(dp, 0, sizeof(dp));
        memset(has, 0, sizeof(has));

        int n = target.size();
        int m = words[0].size();
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 1; j <= words[i].size(); ++j) {
                ++has[j][words[i][j - 1] - 'a'];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (has[m - j + 1][target[n - i] - 'a']) {
                    dp[i][j] = (dp[i][j] + has[m - j + 1][target[n - i] - 'a'] * dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

