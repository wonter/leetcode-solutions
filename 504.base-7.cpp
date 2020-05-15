/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        int flag = num < 0 ? -1 : 1;
        num = abs(num);

        string ret;
        while (num != 0) {
            ret.push_back(num % 7 + '0');
            num /= 7;
        }
        reverse(ret.begin(), ret.end());
        if (flag == -1) {
            ret = "-" + ret;
        }
        return ret;
    }
};
// @lc code=end

