/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        if (position.empty()) {
            return 0;
        }

        sort(position.begin(), position.end());

        int left = 1;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (check(position, m, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    bool check(vector<int>& position, int m, int minimum_magnetic_force) {
        int current = position[0];
        int choose = 1;
        for (size_t i = 1; i < position.size(); ++i) {
            if (position[i] - current >= minimum_magnetic_force) {
                current = position[i];
                ++choose;
            }

            if (choose >= m) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

