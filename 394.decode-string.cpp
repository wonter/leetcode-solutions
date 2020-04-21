#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string ret;

        stack<int> stack1;
        stack<string> stack2;
        int num = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + ch - '0';
                continue;
            }

            if (ch == '[') {
                stack1.push(num);
                stack2.push("");
                num = 0;
                continue;
            }

            if (ch == ']') {
                string temp = repeat(stack1.top(), stack2.top());
                stack1.pop();
                stack2.pop();

                if (stack1.empty()) {
                    ret.append(temp);
                } else {
                    stack2.top().append(temp);
                }
                continue;
            }

            if (stack1.empty()) {
                ret.push_back(ch);
            } else {
                stack2.top().push_back(ch);
            }
        }
        return ret;
    }

private:
    string repeat(size_t times, string str) {
        string s;
        for (int i = 0; i < times; ++i) {
            s.append(str);
        }
        return s;
    }
};
// @lc code=end

