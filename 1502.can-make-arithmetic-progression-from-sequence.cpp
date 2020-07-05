/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.empty()) {
            return true;
        }

        sort(arr.begin(), arr.end());
        int pre = arr[0];
        int interval = INT_MAX;
        for (int i = 1; i < arr.size(); ++i){
            if (interval == INT_MAX) {
                interval = arr[i] - pre;
            }

            if (interval != arr[i] - pre) {
                return false;
            }

            pre = arr[i];
        }
        return true;
    }
};
// @lc code=end

