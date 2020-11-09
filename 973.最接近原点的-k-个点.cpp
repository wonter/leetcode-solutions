/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            int dis_lhs = lhs[0] * lhs[0] + lhs[1] * lhs[1];
            int dis_rhs = rhs[0] * rhs[0] + rhs[1] * rhs[1];
            return dis_lhs < dis_rhs;
        });

        vector<vector<int>> ret;
        copy(points.begin(), points.begin() + K, back_inserter(ret));
        return ret;
    }
};
// @lc code=end
