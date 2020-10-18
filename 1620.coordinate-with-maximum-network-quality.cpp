/*
 * @lc app=leetcode id=1620 lang=cpp
 *
 * [1620] Coordinate With Maximum Network Quality
 */

// @lc code=start
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int ret_x = -100;
        int ret_y = -100;
        int tmp = INT_MIN;

        for (int x = 0; x <= 100; ++x) {
            for (int y = 0; y <= 100; ++y) {
                int c = calc(x, y, towers, radius);
                if (c > tmp) {
                    tmp = c;
                    ret_x = x;
                    ret_y = y;
                }
            }
        }

        return vector<int>{ret_x, ret_y};
    }

    int calc(int x, int y, vector<vector<int>>& towers, int radius) {
        int ret = 0;
        for (const vector<int>& tower : towers) {
            int tower_x = tower[0];
            int tower_y = tower[1];
            int tower_q = tower[2];
            double dis = sqrt((x - tower_x) * (x - tower_x) + (y - tower_y) * (y - tower_y));
            if (dis > radius) {
                continue;
            }

            ret += static_cast<int>(1.0 * tower_q / (1 + dis));
        }
        return ret;
    }
};
// @lc code=end

