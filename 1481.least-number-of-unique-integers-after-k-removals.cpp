#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (int num : arr) {
            counter[num] += 1;
        }

        vector<pair<int, int>> vec;
        for (auto& p : counter) {
            vec.emplace_back(p.second, p.first);
        }
        sort(vec.begin(), vec.end());

        int ans = 0;
        for (auto& p : vec) {
            if (k >= p.first) {
                k -= p.first;
                p.first = 0;
            }

            if (p.first != 0) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

