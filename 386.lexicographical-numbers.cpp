/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    475
 * Dislikes: 66
 * Total Accepted:    48.1K
 * Total Submissions: 97.7K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        dfs(0, n, ret);
        return ret;
    }

    void dfs(int x, int n, vector<int>& ret) {
        if (x) {
            ret.emplace_back(x);
        }

        for (int i = 0; i <= 9; ++i) {
            if (x == 0 && i == 0) {
                continue;
            }

            int new_x = x * 10 + i;
            if (new_x <= n) {
                dfs(new_x, n, ret);
            }
        }
    }
};
// @lc code=end

