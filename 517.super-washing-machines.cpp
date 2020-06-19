#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.empty()) {
            return 0;
        }

        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;

        int ret = 0;
        int sum = 0;
        for (int machine : machines) {
            sum += machine - avg;
            ret = max(ret, max(abs(sum), machine - avg));
        }
        return ret;
    }
};
// @lc code=end
