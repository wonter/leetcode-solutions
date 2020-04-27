/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        string magic = "122";
        for (int i = 2; magic.size() < n; ++i) {
            if (magic[i] == '1') {
                if (magic.back() == '1') {
                    magic.append("2");
                } else {
                    magic.append("1");
                }
            } else {
                if (magic.back() == '1') {
                    magic.append("22");
                } else {
                    magic.append("11");
                }
            }
        }

        return count_if(magic.begin(), magic.begin() + n, [](char ch) { return ch == '1'; });
    }
};
// @lc code=end

