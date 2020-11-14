/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[100][5];
        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start < 5; ++start) {
                if (len == 1) {
                    dp[len][start] = 1;
                } else {
                    dp[len][start] = 0;
                    for (int next_start = start; next_start < 5; ++next_start) {
                        dp[len][start] += dp[len - 1][next_start];
                    }
                }

                // cout << len << " " << start << " " << dp[len][start] << endl;
            }
        }

        int ans = 0;
        for (int start = 0; start < 5; ++start) {
            ans += dp[n][start];
        }
        return ans;
    }
};
// @lc code=end

