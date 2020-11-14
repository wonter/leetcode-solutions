/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

// @lc code=start
using IntPair = pair<int, int>;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });

        int ans = INT_MIN;
        for (int i = 1; i < points.size(); ++i) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};
// @lc code=end

