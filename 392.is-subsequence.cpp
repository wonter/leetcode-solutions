/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }

        int pos = 0;
        for (char ch : t) {
            if (ch == s[pos]) {
                ++pos;
            }

            if (pos == s.length()) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

