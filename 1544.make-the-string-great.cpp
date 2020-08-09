/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && st.top() != ch && tolower(st.top()) == tolower(ch)) {
                st.pop();
                continue;
            } else {
                st.push(ch);
            }
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

