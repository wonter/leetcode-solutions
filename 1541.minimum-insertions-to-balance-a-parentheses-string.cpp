/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;

        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                if (st.empty()) {
                    st.push('(');
                } else {
                    if (st.top() == ')') {
                        ++ans;
                        st.pop();
                        st.pop();
                    }
                    st.push('(');
                }
            } else {
                if (st.empty()) {
                    ++ans;
                    st.push('(');
                    st.push(')');
                } else {
                    if (st.top() == ')') {
                        st.pop();
                        st.pop();
                    } else {
                        st.push(')');
                    }
                }
            }
        }

        while (!st.empty()) {
            if (st.top() == ')') {
                ++ans;
                st.pop();
                st.pop();
            } else {
                ans += 2;
                st.pop();
            }
        }

        return ans;
    }
};
// @lc code=end

