/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;

        int x = 0;
        int y = 0;
        visited.insert({x, y});
        for (char ch : path) {
            switch (ch) {
            case 'N':
                y += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'E':
                x += 1;
                break;
            case 'W':
                x -= 1;
                break;
            } 

            auto res = visited.insert({x, y});
            if (!res.second) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

