/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if (mat.empty()) {
            return 0;
        }

        int row[110] = {};
        int col[110] = {};

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }

};
// @lc code=end

