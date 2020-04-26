/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0;
        int ret = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                ++zero;
            }

            int one = 0;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '1') {
                    ++one;
                }
            }

            cout << zero << " " << one << endl;

            ret = max(ret, zero + one);
        }
        return ret;
    }
};
// @lc code=end

