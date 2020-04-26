/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        vector<int> links[200000];

        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            int m = nums[i].size();
            for (int j = 0; j < m; ++j) {
                links[i + j].emplace_back(nums[i][j]);
            }
        }

        for (int i = 0; i < 200000; ++i) {
            ret.insert(ret.end(), links[i].begin(), links[i].end());
        }

        return ret;
    }
};
// @lc code=end

