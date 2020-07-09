/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        unordered_set<string> st;
        for (int i = 0; i <= n - k; ++i) {
            st.insert(s.substr(i, k));
        }

        return st.size() == (1 << k);
    }
};
// @lc code=end

