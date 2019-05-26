/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ordered_heights = heights;
        sort(ordered_heights.begin(), ordered_heights.end());
        
        int ret = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            if (ordered_heights[i] != heights[i]) {
                ++ret;
            }
        }
        return ret;
    }
};

