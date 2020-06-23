/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.emplace_back(h);
        verticalCuts.emplace_back(w);

        int pre_horizontalCuts = 0;
        int max_horizontalCuts = 0;
        for (int i = 0; i < horizontalCuts.size(); ++i) {
            max_horizontalCuts = max(max_horizontalCuts, horizontalCuts[i] - pre_horizontalCuts);
            pre_horizontalCuts = horizontalCuts[i];
        }

        int pre_verticalCuts = 0;
        int max_verticalCuts = 0;
        for (int i = 0; i < verticalCuts.size(); ++i) {
            max_verticalCuts = max(max_verticalCuts, verticalCuts[i] - pre_verticalCuts);
            pre_verticalCuts = verticalCuts[i];
        }

        return static_cast<long long>(max_verticalCuts) * max_horizontalCuts % 1000000007;
    }
};
// @lc code=end

