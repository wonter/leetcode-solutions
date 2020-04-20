/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
    public:
        int lastRemaining(int n) {
            return elimination(n, 1);
        }
    private:
    int is_odd(int n) {
        // or n % 2 != 0
        return n & 1;
    }
    
    int elimination(int n, int left2right) {
        if (n == 1) {
            return n;
        }
    
        if (is_odd(n)) {
            return elimination(n / 2, !left2right) * 2;
        } else if (left2right) {
            return elimination(n / 2, !left2right) * 2;
        } else {
            return elimination(n / 2, !left2right) * 2 - 1;
        }
    }
};
// @lc code=end

