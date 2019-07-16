/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.49%)
 * Likes:    323
 * Dislikes: 149
 * Total Accepted:    117.7K
 * Total Submissions: 290.7K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
		if (num <= 0) {
			return false;
        }

		if ((num & (num - 1)) != 0) {
			return false;
        }

		if ((num & 0x55555555) == num) {
			return true;
        }

		return false;
    }
};

