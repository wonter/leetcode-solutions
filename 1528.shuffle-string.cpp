/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret;
        ret.resize(s.size());

        for (int i = 0; i < indices.size(); ++i) {
            ret[indices[i]] = s[i];
        }

        return ret;
    }
};
// @lc code=end
