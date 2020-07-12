/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

// @lc code=start
class Solution {
public:
    int numSub(string s) {
        long long continous = 0;
        long long ret = 0;
        for (char ch : s) {
            if (ch == '1') {
                continous += 1;
            } else {
                ret = ret + (continous * (continous + 1) / 2) % 1000000007;
                continous = 0;
            }
        }
        ret = (ret + continous * (continous + 1) / 2) % 1000000007;
        return ret;
    }
};
// @lc code=end

