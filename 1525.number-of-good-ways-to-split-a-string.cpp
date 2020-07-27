/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */

// @lc code=start
class Solution {
public:
    int numSplits(string s) {
        int suffix[26] = {};
        for (char ch : s) {
            suffix[ch - 'a'] += 1;
        }
        int prefix[26] = {};

        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            prefix[s[i] - 'a'] += 1;
            suffix[s[i] - 'a'] -= 1;

            if (diff_count(prefix) == diff_count(suffix)) {
                ans += 1;
            }
        }

        return ans;
    }

private:
    int diff_count(int counter[26]) {
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (counter[i]) {
                 ret += 1;
            }
        }
        return ret;
    }
};
// @lc code=end