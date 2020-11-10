/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = n - 2;
        while (pos >= 0 && nums[pos] >= nums[pos + 1]) {
            --pos;
        }

        if (pos >= 0) {
            int min_pos = -1;
            for (int i = n - 1; i > pos; --i) {
                if (nums[i] > nums[pos] && (min_pos == -1 || nums[min_pos] > nums[i])) {
                    min_pos = i;
                }
            }
            swap(nums[pos], nums[min_pos]);
        }

        if (pos + 1 >= 0) {
            reverse(nums.begin() + pos + 1, nums.end());
        }
    }
};
// @lc code=end

