/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_map<int, unordered_map<int, int>> blocked_map;
        for (const vector<int>& block : blocked) {
            blocked_map[block[0]][block[1]] = true;
        }

        return !in_fence(source[0], source[1], target[0], target[1], 0, blocked, blocked_map) && !in_fence(target[0], target[1], source[0], source[1], 0, blocked, blocked_map);
    }

private:
    using Point = pair<int, int>;

    bool in_fence(int x, int y, int xx, int yy, int depth, const vector<vector<int>>& blocked, const unordered_map<int, unordered_map<int, int>>& blocked_map) {
        const static int dx[4] = {-1, 1, 0, 0};
        const static int dy[4] = {0, 0, 1, -1};

        queue<Point> que;
        unordered_map<int, unordered_map<int, int>> dis;

        dis[x][y] = 1;
        que.push(Point{x, y});
        while (!que.empty()) {
            Point front = que.front();
            que.pop();

            if (dis[front.first][front.second] >= 500 || (front.first == xx && front.second == yy)) {
                return false;
            }

            for (int i = 0; i < 4; i++) {
                int nx = front.first + dx[i];
                int ny = front.second + dy[i];

                if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) {
                    continue;
                }

                auto it = blocked_map.find(nx);
                if (it != blocked_map.end()) {
                    auto itt = it->second.find(ny);
                    if (itt != it->second.end()) {
                        continue;
                    }
                }

                if (dis[nx][ny] == 0) {
                    dis[nx][ny] = dis[front.first][front.second] + 1;
                    que.push(Point{nx, ny});
                }
            }
        }

        return true;
    }
};
