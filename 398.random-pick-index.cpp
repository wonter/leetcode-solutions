#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            _nums.emplace_back(pair<int, int>{nums[i], i});
        }
        sort(_nums.begin(), _nums.end());
        srand(time(nullptr));
    }
    
    int pick(int target) {
        int left = lower_bound(_nums.begin(), _nums.end(), pair<int, int>{target, INT_MIN}) - _nums.begin();
        int right = upper_bound(_nums.begin(), _nums.end(), pair<int, int>{target, INT_MAX}) - _nums.begin();

        if (left == right) {
            return 0;
        }
        cout << left << " " << right << endl;

        // [left, right)
        return _nums[rand() % (right - left) + left].second;
    }

private:
    vector<pair<int, int>> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

