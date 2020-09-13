/*
 * @lc app=leetcode id=1585 lang=cpp
 *
 * [1585] Check If String Is Transformable With Substring Sort Operations
 */

// @lc code=start
class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int> que[10];
        for (int i = 0; i < s.size(); ++i) {
            que[s[i] - '0'].push(i);
        }

        for (int i = 0; i < t.size(); ++i) {
            int target = t[i] - '0';
            if (que[target].empty()) {
                return false;
            }

            for (int j = 0; j < target; ++j) {
                if (!que[j].empty() && que[j].front() < que[target].front()) {
                    return false;
                }
            }

            que[target].pop();
        }

        return true;
    }
};
// @lc code=end

