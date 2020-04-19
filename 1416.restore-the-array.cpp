/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
const int mod = 1000000007;
int dp[100050];
long long ten[10];
class Solution {
public:
    int numberOfArrays(string str, int k) {
        dp[0] = 1;

        ten[0] = 1;
        for (int i = 1; i <= 9; ++i) {
            ten[i] = ten[i - 1] * 10;
        }

        int len = str.size();
        for (int i = 1; i <= len; ++i) {

            long long num = 0;
            int s = i;
            int e = max(i - 9, 1);
            dp[i] = 0;
            for (int j = s; j >= e; --j) {
                num += static_cast<long long>(str[j - 1] - '0') * ten[i - j];
                if (j != i && str[j - 1] == '0') {
                    continue;
                }
                if (num < 1 || num > k) {
                    continue;
                }

                dp[i] = (dp[i] + dp[j - 1]) % mod;
            }

        }

        return dp[str.size()];
    }
};
// @lc code=end

