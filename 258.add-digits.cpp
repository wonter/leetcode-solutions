/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (54.38%)
 * Likes:    480
 * Dislikes: 806
 * Total Accepted:    243.8K
 * Total Submissions: 448.2K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */
class Solution {
public:
    int addDigits(int num) {
        int digits_sum = num;

        while (digits_sum >= 10) {
            num = digits_sum;
            digits_sum = 0;
            while (num) {
                digits_sum += num % 10;
                num /= 10;
            }
        }

        return digits_sum;
    }
};

