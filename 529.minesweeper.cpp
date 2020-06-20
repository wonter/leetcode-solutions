#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty()) {
            return board;
        }

        dfs(board, click[0], click[1]);

        return board;
    }

private:
    int calc_mine(vector<vector<char>>& board, int x, int y) {
        int n = board.size();
        int m = board[0].size();
        int mine_num = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + _dx[i];
            int ny = y + _dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (board[nx][ny] == 'M') {
                    ++mine_num;
                }
            }
        }
        return mine_num;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        int n = board.size();
        int m = board[0].size();

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        assert(board[x][y] == 'E');

        int mine_num = calc_mine(board, x, y);
        cout << x << " " << y << " " << mine_num << endl;
        if (mine_num > 0) {
            board[x][y] = '0' + mine_num;
            return;
        }

        board[x][y] = 'B';
        for (int i = 0; i < 8; ++i) {
            int nx = x + _dx[i];
            int ny = y + _dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'E') {
                dfs(board, nx, ny);
            }
        }
    }

    const int _dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int _dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
};
// @lc code=end

