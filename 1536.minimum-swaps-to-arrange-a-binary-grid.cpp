/*
 * @lc app=leetcode id=1536 lang=cpp
 *
 * [1536] Minimum Swaps to Arrange a Binary Grid
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        int min_step = 0;
        for (int i = 0; i < n; ++i) {
            int row = -1;
            for (int j = i; j < n; ++j) {
                if (suffix_zero(grid[j]) >= n - i - 1) {
                    row = j;
                    break;
                }
            }
            if (row == -1) {
                return -1;
            }

            for (int j = row; j > i; --j) {
                swap(grid[j], grid[j - 1]);
                min_step += 1;
            }
        }
        return min_step;
    }

private:
    int suffix_zero(const vector<int>& vec) {
        int ret = 0;
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            if (*it == 0) {
                ret += 1;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

