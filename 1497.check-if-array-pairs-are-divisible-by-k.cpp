/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for (int& x : arr) {
            x %= k;
        }

        int pairs = 0;
        unordered_map<int, int> counter;
        for (int x : arr) {
            int need = -x;
            if (counter[need] >= 1) {
                ++pairs;
                counter[need] -= 1;
                continue;
            }

            if (x >= 0) {
                need = k - x;
            } else {
                need = -k - x;
            }
            if (counter[need] >= 1) {
                ++pairs;
                counter[need] -= 1;
                continue;
            }

            counter[x] += 1;
        }

        return pairs == arr.size() / 2;
    }
};
// @lc code=end

