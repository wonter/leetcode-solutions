/*
 * @lc app=leetcode id=1559 lang=cpp
 *
 * [1559] Detect Cycles in 2D Grid
 */

// @lc code=start
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return false;
        }

        memset(vis, 0, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] == 0 && dfs(grid, i, j, -1, -1, 1)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool dfs(const vector<vector<char>>& grid, int x, int y, int pre_x, int pre_y, int depth) {
        static const int dx[4] = {1, -1, 0, 0};
        static const int dy[4] = {0, 0, 1, -1};
        
        vis[x][y] = 1;
        
        bool ret = false;
        for (int i = 0; i < 4 && ret == false; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (nx == pre_x && ny == pre_y) {
                continue;
            }
            if (grid[nx][ny] != grid[x][y]) {
                continue;
            }
            
            if (vis[nx][ny] == 0) {
                ret |= dfs(grid, nx, ny, x, y, depth + 1);
            } else if (depth >= 4) {
                ret = true;
            }
        }
        
        return ret;
    }

private:
    int n;
    int m;
    int vis[550][550];
};
// @lc code=end

