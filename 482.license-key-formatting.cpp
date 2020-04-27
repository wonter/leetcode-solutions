/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        vector<string> groups;
        string group;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == '-') {
                continue;
            }

            group.push_back(toupper(S[i]));
            if (group.size() == K) {
                reverse(group.begin(), group.end());
                groups.emplace_back(group);
                group.clear();
            }
        }
        if (!group.empty()) {
            reverse(group.begin(), group.end());
            groups.emplace_back(group);
        }

        string ret;
        for (auto it = groups.rbegin(); it != groups.rend(); ++it) {
            if (it != groups.rbegin()) {
                ret.push_back('-');
            }
            ret.append(*it);
        }
        return ret;
    }
};
// @lc code=end
