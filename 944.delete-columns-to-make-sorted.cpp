/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty()) {
            return 0;
        }

        int n = A.size();
        int m = A[0].size();
        int ret = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (A[i][j] < A[i - 1][j]) {
                    ++ret;
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

