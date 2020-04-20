/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> counter;
        long long min_y = INT_MAX;
        long long max_y = INT_MIN;
        long long min_x = INT_MAX;
        long long max_x = INT_MIN;
        long long total_area = 0;
        for (const vector<int>& rectangle : rectangles) {
            long long bottom_left_x = rectangle[0];
            long long bottom_left_y = rectangle[1];
            long long top_right_x = rectangle[2];
            long long top_right_y = rectangle[3];
            total_area += (top_right_x - bottom_left_x) * (top_right_y - bottom_left_y);

            max_y = max(max_y, top_right_y);
            min_y = min(min_y, bottom_left_y);
            max_x = max(max_x, top_right_x);
            min_x = min(min_x, bottom_left_x);

            ++counter[{bottom_left_x, bottom_left_y}];
            ++counter[{top_right_x, top_right_y}];
            ++counter[{bottom_left_x, top_right_y}];
            ++counter[{top_right_x, bottom_left_y}];
        }

        for (auto it = counter.begin(); it != counter.end(); ++it) {
            const pair<int, int>& p = it->first;
            if (p.first == max_x && p.second == max_y) {
                if (it->second != 1) {
                    return false;
                }
                continue;
            }
            if (p.first == min_x && p.second == max_y) {
                if (it->second != 1) {
                    return false;
                }
                continue;
            }
            if (p.first == max_x && p.second == min_y) {
                if (it->second != 1) {
                    return false;
                }
                continue;
            }
            if (p.first == min_x && p.second == min_y) {
                if (it->second != 1) {
                    return false;
                }
                continue;
            }

            if (it->second % 2 != 0) {
                return false;
            }
        }

        return total_area == (max_x - min_x) * (max_y - min_y);
    }
};
// @lc code=end
