/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    481
 * Dislikes: 109
 * Total Accepted:    117.1K
 * Total Submissions: 292K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
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
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid > num) {
                r = mid - 1;
            } else if (mid * mid < num) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

