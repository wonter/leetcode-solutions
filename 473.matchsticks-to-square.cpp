#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }

        int side = sum / 4;
        int vis[20] = {};
        if (dfs(nums, vis, side, 0, 0, 0)) {
            return true;
        }
        return false;
    }

private:
    bool dfs(const vector<int>& nums, int* vis, int side, int sum, int satisfy, int i) {
        if (satisfy == 4) {
            if (accumulate(vis, vis + nums.size(), 0) == nums.size()) {
                return true;
            }
            return false;
        }

        if (sum > side) {
            return false;
        }

        if (sum == side && dfs(nums, vis, side, 0, satisfy + 1, 0)) {
            return true;
        }
        
        if (i == nums.size()) {
            return false;
        }

        if (dfs(nums, vis, side, sum, satisfy, i + 1)) {
            return true;
        }

        if (vis[i] == 0) {
            vis[i] = 1;
            if (dfs(nums, vis, side, sum + nums[i], satisfy, i + 1)) {
                return true;
            }
            vis[i] = 0;
        }

        return false;
    }
};
// @lc code=end
