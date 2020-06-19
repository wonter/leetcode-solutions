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

        int left_dress = 0;
        int left_machine = 0;
        int right_dress = sum;
        int right_machine = n;
        int ret = 0;
        for (int machine : machines) {
            right_dress -= machine;
            right_machine -= 1;

            if (right_dress > right_machine * avg && (left_dress + machine) <= (left_machine + 1) * avg) {
                ret = max(ret, right_dress - right_machine * avg);
            } else if ((right_dress + machine) <= (right_machine + 1) * avg && left_dress > left_machine * avg) {
                ret = max(ret, left_dress - left_machine * avg);
            } else if (right_dress <= right_machine * avg && left_dress <= left_machine * avg) {
                ret = max(ret, machine - avg);
            } else if (right_dress >= right_machine * avg && left_dress >= left_machine * avg) {
                ret = max(ret, max(right_dress - right_machine * avg, left_dress - left_machine * avg));
            }

            left_dress += machine;
            left_machine += 1;
        }

        return ret;
    }
};
// @lc code=end
