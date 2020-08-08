/*
 * @lc app=leetcode id=1542 lang=cpp
 *
 * [1542] Find Longest Awesome Substring
 */

// @lc code=start
class Solution {
public:
    int longestAwesome(string s) {
        int pre[1024];
        memset(pre, -1, sizeof(pre));

        int ans = 1;
        int current_status = 0;
        for (int i = 0; i < s.size(); ++i) {
            current_status ^= (1 << (s[i] - '0'));

            if (current_status == 0) {
                ans = i + 1;
            } else {
                if (pre[current_status] != -1) {
                    ans = max(ans, i - pre[current_status]);
                }
            }

            for (int j = 0; j < 10; ++j) {
                int need_status = current_status ^ (1 << j);
                if (need_status == 0) {
                    ans = max(ans, i + 1);
                } else {
                    if (pre[need_status] != -1) {
                        ans = max(ans, i - pre[need_status]);
                    }
                }
            }

            if (pre[current_status] == -1) {
                pre[current_status] = i;
            }
        }

        return ans;
    }
};
// @lc code=end

