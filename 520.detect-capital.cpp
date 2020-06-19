/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (char ch : word) {
            if (isupper(ch)) {
                ++upper;
            }
        }
        if (upper == word.size() || upper == 0) {
            return true;
        }
        if (upper != 1) {
            return false;
        }
        return isupper(word[0]);
    }
};
// @lc code=end

