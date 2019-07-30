/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.09%)
 * Likes:    458
 * Dislikes: 155
 * Total Accepted:    105.8K
 * Total Submissions: 239.4K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        size_t res_len = max(num1.size(), num2.size());
        int carry = 0;
        for (size_t i = 0; i < res_len; ++i) {
            int digit_sum = 0;
            if (i < num1.size()) {
                digit_sum += num1[i] - '0';
            }
            if (i < num2.size()) {
                digit_sum += num2[i] - '0';
            }
            digit_sum += carry;
            carry = digit_sum / 10;
            digit_sum %= 10;
            res.push_back(digit_sum + '0');
        }
        if (carry) {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

