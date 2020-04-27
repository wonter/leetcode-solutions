#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        for (int i = 0; i < 32 && num != 0; ++i, num >>= 1) {
            if ((num & 1) == 0) {
                ret |= 1 << i;
            }
        }
        return ret;
    }
};
// @lc code=end

