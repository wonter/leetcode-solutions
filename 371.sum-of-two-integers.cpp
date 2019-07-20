/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.85%)
 * Likes:    795
 * Dislikes: 1431
 * Total Accepted:    140.4K
 * Total Submissions: 276K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        return static_cast<int>(get_sum(static_cast<unsigned>(a), static_cast<unsigned>(b)));
    }

private:
    int get_sum(unsigned a, unsigned b) {
        if (a == 0) {
            return b;
        }

        if (b == 0) {
            return a;
        }
        return get_sum(a^b, (a&b)<<1);
    }
};

