/*
 * @lc app=leetcode id=1414 lang=cpp
 *
 * [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 */

// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long fib[60];
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i < 60; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        int ans = 0;
        for (int i = 59; i >= 0; --i) {
            while (k >= fib[i]) {
                k -= fib[i];
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

