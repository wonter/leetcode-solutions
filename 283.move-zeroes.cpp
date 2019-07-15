/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (54.65%)
 * Likes:    2149
 * Dislikes: 79
 * Total Accepted:    488.5K
 * Total Submissions: 893.6K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        while (i < nums.size() && j < nums.size()) {
            while (i < nums.size() && nums[i] != 0) {
                ++i;
            }

            while (j <= i || (j < nums.size() && nums[j] == 0)) {
                ++j;
            }

            if (i < nums.size() && j < nums.size()) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};

