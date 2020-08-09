/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        char ans = '0';
        for (int i = 0; i < k; ++i) {
            if (i >= s.size()) {
                string new_s = s;
                transform(new_s.begin(), new_s.end(), new_s.begin(), [](char ch) {
                    if (ch == '0') {
                        return '1';
                    }
                    return '0';
                });
                reverse(new_s.begin(), new_s.end());

                s.push_back('1');
                s.append(new_s);
            }

            ans = s[i];
        }
        return ans;
    }
};
// @lc code=end

