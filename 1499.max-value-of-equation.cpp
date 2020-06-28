/*
 * @lc app=leetcode id=1499 lang=cpp
 *
 * [1499] Max Value of Equation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();

        int ans = INT_MIN;
        deque<pair<int, int>> que;
        for (vector<int>& point : points) {
            int x = point[0];
            int y = point[1];
            int sum = x + y;
            int weight = y - x;

            while (!que.empty() && x - que.front().first > k) {
                que.pop_front();
            }

            if (!que.empty()) {
                ans = max(ans, que.front().second + sum);
            }

            while (!que.empty() && weight >= que.back().second) {
                que.pop_back();
            }
            que.push_back({x, weight});
// 
//             deque<pair<int, int>> tmp = que;
//             while (!tmp.empty()) {
//                 cout << "{" << tmp.front().first << ", " << tmp.front().second << "} ";
//                 tmp.pop_front();
//             }
//             cout << endl;
        }
        return ans;
    }
};
// @lc code=end

