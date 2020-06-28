/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int idx = 0;
        for (int i = 1;i <= n; ++i) {
            if (n % i == 0) {
                ++idx;
                if (idx == k) {
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

