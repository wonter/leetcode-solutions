/*
 * @lc app=leetcode id=1625 lang=cpp
 *
 * [1625] Lexicographically Smallest String After Applying Operations
 */

// @lc code=start
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ret = s;
        int n = s.size();
        int even_max_add = b&1 ? 9 : 0;
        int odd_max_add = 9;

        for (int even_add = 0; even_add <= even_max_add; ++even_add) {
            for (int odd_add = 0; odd_add <= odd_max_add; ++odd_add) {
                string new_s = s;
                for (int i = 0; i < n; ++i) {
                    if (i & 1) {
                        new_s[i] = (new_s[i] - '0' + a * odd_add) % 10 + '0';
                    } else {
                        new_s[i] = (new_s[i] - '0' + a * even_add) % 10 + '0';
                    }
                }
                ret = min(ret, min_lexi(std::move(new_s), b));
            }
        }

        return ret;
    }

    string min_lexi(string&& s, int b) {
        int n = s.size();
        string ret = s;
        // cout << "-----------" << s << "-----------" << endl;
        for (int i = 0; i < n; ++i) {
            s = s.substr(s.size() - b) + s.substr(0, s.size() - b);
            ret = min(ret, s);
        }
        // cout << "-----------" << s << "-----------" << endl;
        return ret;
    }
};
// @lc code=end

