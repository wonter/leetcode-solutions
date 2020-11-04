#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        vector<vector<int>> ret;
        bool found = false;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            if (newInterval[0] > intervals[i][1]) {
                ret.emplace_back(intervals[i]);
                continue;
            }

            if (newInterval[1] < intervals[i][0]) {
                if (!found) {
                    ret.emplace_back(newInterval);
                    found = true;
                }
                ret.emplace_back(intervals[i]);
                continue;
            }

            int start = min(newInterval[0], intervals[i][0]);
            int end = -1;
            int j = i;
            while (j < n && newInterval[1] >= intervals[j][0]) {
                ++j;
            }
            end = max(newInterval[1], j > 0 ? intervals[j - 1][1] : INT_MIN);
            ret.emplace_back(vector<int>{start, end});
            if (j != n) {
                ret.emplace_back(intervals[j]);
            }
            i = j;
            found = true;
        }
        if (!found) {
            ret.emplace_back(newInterval);
        }
        return ret;
    }
};
// @lc code=end

