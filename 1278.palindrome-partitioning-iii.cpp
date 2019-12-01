class Solution {
public:
    int palindromePartition(string s, int k) {
        int dp[s.size() + 1][k + 1];
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = s.size();
            }
        }
        dp[0][0] = 0;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int l = 1; l <= i; ++l) {
                    dp[i][j] = min(dp[i][j], dp[i - l][j - 1] + make_palindromic(s, i - l, i - 1));
                }
            }
        }

        return dp[s.size()][k];
    }

    int make_palindromic(const std::string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (s[i] == s[j]) {
            return make_palindromic(s, i + 1, j - 1);
        }
        return make_palindromic(s, i + 1, j - 1) + 1;
    }
};