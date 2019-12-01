class Solution {
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, -1));
        return dfs(s, dp, 0, k);
    }

    int dfs(const string& s, vector<vector<int>>& dp, int i, int k) {
        cout << i << ", " << k << endl;
        if (s.size() - i < k) {
            return 1000000;
        }
        if (i == s.size() && k == 0) {
            return 0;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        dp[i][k] = 1000000;
        for (int l = 1; l <= s.size() - i; ++l) {
            dp[i][k] = min(dp[i][k], make_palindromic(s, i, i + l) + dfs(s, dp, i + l, k - 1));
        }
        return dp[i][k];
    }

    // [i, j)
    int make_palindromic(const std::string& s, int i, int j) {
        if (j - i <= 1) {
            return 0;
        }
        if (s[i] == s[j - 1]) {
            return make_palindromic(s, i + 1, j - 1);
        }
        return make_palindromic(s, i + 1, j - 1) + 1;
    }
};