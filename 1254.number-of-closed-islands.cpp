/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (53.75%)
 * Likes:    3
 * Dislikes: 1
 * Total Accepted:    1.4K
 * Total Submissions: 2.6K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        // 0: 没有访问过
        // 1: 正在访问
        // 2: 访问过并且不被1包围
        // 3: 访问过并且被1包围
        vector<vector<int>> status(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (status[i][j] != 0) {
                    continue;
                }

                if (grid[i][j] == 1) {
                    continue;
                }

                if (!escape(i, j, n, m, status, grid)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    bool escape(int x, int y, int n, int m, vector<vector<int>>& status, const vector<vector<int>>& grid) {
        static const int dx[4] = {1, -1, 0, 0};
        static const int dy[4] = {0, 0, 1, -1};
        
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return true;
        }
        if (grid[x][y] == 1) {
            return false;
        }
        switch (status[x][y]) {
            case 1:
            case 3:
                return false;
            case 2:
                return true;
        }

        status[x][y] = 1;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (escape(nx, ny, n, m, status, grid)) {
                status[x][y] = 2;
                return true;
            }
        }
        
        status[x][y] = 3;
        return false;
    }
};
// @lc code=end

