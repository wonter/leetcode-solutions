/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

// @lc code=start
class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        string ret;
        int counter = 0;
        for (int i = str.size() - 1; i >= 0; --i) {
            ret.push_back(str[i]);
            ++counter;
            if (counter == 3 && i != 0) {
                ret.push_back('.');
                counter = 0;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

