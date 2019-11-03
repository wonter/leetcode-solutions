/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (50.53%)
 * Likes:    0
 * Dislikes: 1
 * Total Accepted:    1.6K
 * Total Submissions: 3.2K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters. 
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * 
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "(a(b(c)d)"
 * Output: "a(b(c)d)"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is one of  '(' , ')' and lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }

        unordered_map<int, bool> remove;
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                que.push(i);
            }
            if (s[i] == ')') {
                if (que.empty()) {
                    remove[i] = true;
                } else {
                    que.pop();
                }
            }
        }

        while (!que.empty()) {
            remove[que.front()] = true;
            que.pop();
        }

        std::string ret;
        for (int i = 0; i < n; ++i) {
            if (!remove[i]) {
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};
// @lc code=end

