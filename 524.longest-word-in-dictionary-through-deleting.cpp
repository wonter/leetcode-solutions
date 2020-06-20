/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ret;
        for (int i = 0; i < d.size(); ++i) {
            if (check(s, d[i]) && (d[i].size() > ret.size() || (d[i].size() == ret.size() && d[i] < ret))) {
                ret = d[i];
            }
        }
        return ret;
    }

private:
    bool check(const string& s1, const string& s2) {
        if (s2.empty()) {
            return true;
        }

        int j = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[j]) {
                ++j;
            }
            if (j == s2.size()) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

