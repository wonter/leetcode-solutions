#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = 1000000000;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (check(bloomDay, m, k, left)) {
            return left;
        }
        return -1;
    }

private:
    bool check(vector<int>& bloomDay, int m, int k, int day_after) {
        int n = bloomDay.size();
        int continuous = 0;
        int bouquets = 0;
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] > day_after) {
                continuous = 0;
                continue;
            }

            continuous += 1;
            if (continuous >= k) {
                bouquets += 1;
                continuous = 0;
            }
        }
        return bouquets >= m;
    }
};
// @lc code=end

