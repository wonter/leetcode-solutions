/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = INT_MIN;

        for (int num : left) {
            ret = max(ret, num);
        }
        for (int num : right) {
            ret = max(ret, n - num);
        }

        return ret;
    }
};
// @lc code=end

