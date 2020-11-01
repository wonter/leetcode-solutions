/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = 1000000;
        while (left < right) {
            int mid = (left + right) / 2;
            memset(vis, 0, sizeof(vis));
            if (dfs(heights, 0, 0, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool dfs(const vector<vector<int>>& heights, int x, int y, int max_gap) {
        static constexpr int dx[4] = {1, -1, 0, 0};
        static constexpr int dy[4] = {0, 0, 1, -1};

        int n = heights.size();
        int m = heights[0].size();
        assert(x < n);
        assert(y < m);
        vis[x][y] = 1;

        if (x == n - 1 && y == m - 1) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) {
                continue;
            }
            if (ny < 0 || ny >= m) {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            int gap = abs(heights[nx][ny] - heights[x][y]);
            if (gap > max_gap) {
                continue;
            }

            vis[nx][ny] = 1;
            if (dfs(heights, nx, ny, max_gap)) {
                return true;
            }
        }
        return false;
    }

    int vis[110][110];
};
// @lc code=end
