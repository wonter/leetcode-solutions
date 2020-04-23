/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(long long n) {
        cout << n << endl;
        if (n <= 3) {
            return n - 1;
        }

        if ((n & 0x03) == 0x03) {
            return integerReplacement(n + 1) + 1;
        }

        if ((n & 0x01) == 0x01) {
            return integerReplacement(n - 1) + 1;
        }

        return integerReplacement(n >> 1) + 1;
    }
};
// @lc code=end
