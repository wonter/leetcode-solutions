/*
 * @lc app=leetcode id=1012 lang=cpp
 *
 * [1012] Numbers With Repeated Digits
 */

// @lc code=start
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        if (N == 0) {
            return 0;
        }

        int n = N;

        int digits[10];
        int pos = 0;
        while (N != 0) {
            digits[pos] = N % 10;
            pos += 1;
            N /= 10;
        }

        int dp[10][1 << 10][2][2];
        memset(dp, -1, sizeof(dp));

        return n + 1 - dfs(digits, dp, pos - 1, 0, true, true);
    }

private:
    int dfs(int digits[10], int dp[10][1 << 10][2][2], int pos, int already_taken, bool lead_zero, bool limit) {
        if (pos == -1) {
            return 1;
        }

        if (dp[pos][already_taken][lead_zero][limit] != -1) {
            return dp[pos][already_taken][lead_zero][limit];
        }

        dp[pos][already_taken][lead_zero][limit] = 0;
        for (int current_digit = 0; current_digit <= (limit ? digits[pos] : 9); ++current_digit) {
            if (already_taken & (1 << current_digit)) {
                if (current_digit > 0) {
                    continue;
                } 
                if (current_digit == 0 && !lead_zero) {
                    continue;
                }
            }

            if (lead_zero && current_digit == 0) {
                dp[pos][already_taken][lead_zero][limit] += dfs(digits, dp,
                    pos - 1, already_taken, lead_zero && current_digit == 0,
                    limit && current_digit == digits[pos]);
            } else {
                dp[pos][already_taken][lead_zero][limit] += dfs(digits, dp,
                    pos - 1, already_taken | (1 << current_digit), lead_zero && current_digit == 0,
                    limit && current_digit == digits[pos]);
            }
        }

        return dp[pos][already_taken][lead_zero][limit];
    }
};
// @lc code=end
