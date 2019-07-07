/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid.empty()) {
            return grid;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> new_grid = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        dfs(r0, c0, n, m, color, grid, vis, new_grid);

        return new_grid;
    }
private:
    void dfs(int r, int c, int n, int m, int new_color, const vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& new_grid) {
        static const int dr[4] = {1, -1, 0, 0};
        static const int dc[4] = {0, 0, 1, -1};

        vis[r][c] = true;

        bool is_border = false;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr == -1 || nr == n || nc == -1 || nc == m) {
                is_border = true;
                continue;
            }
            if (vis[nr][nc]) {
                continue;
            }

            if (grid[nr][nc] != grid[r][c]) {
                is_border = true;
            } else {
                dfs(nr, nc, n, m, new_color, grid, vis, new_grid);
            }
        }

        if (is_border) {
            new_grid[r][c] = new_color;
        }
    }
};