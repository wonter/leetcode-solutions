/*
 * @lc app=leetcode id=1540 lang=cpp
 *
 * [1540] Can Convert String in K Moves
 */

// @lc code=start
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) {
            return false;
        }

        int n = s.size();
        int need_move[26] = {};
        for (int i = 1; i < 26; ++i) {
            need_move[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) {
                continue;
            }

            for (int j = 1; j < 26; ++j) {
                if ((s[i] - 'a' + j) % 26 == t[i] - 'a') {
                    int real_need = need_move[j];
                    need_move[j] += 26;

                    if (real_need > k) {
                        return false;
                    }

                    break;
                }
            }
        }

        return true;
    }
};
// @lc code=end

