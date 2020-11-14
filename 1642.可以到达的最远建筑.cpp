/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(heights, mid, bricks, ladders)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    bool check(vector<int>& heights, int max_i, int bricks, int ladders) {
        vector<int> gaps;
        for (int i = 1; i <= max_i; ++i) {
            int gap = heights[i] - heights[i - 1];
            if (gap > 0) {
                gaps.emplace_back(gap);
            }
        }
        sort(gaps.begin(), gaps.end(), greater<int>());

        int sum = 0;
        for (int i = ladders; i < gaps.size(); ++i) {
            sum += gaps[i];
        }
        return sum <= bricks;
    }
};
// @lc code=end

