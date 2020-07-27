/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ret = target[0];
        int n = target.size();
        for (int i = 1; i < target.size(); ++i) {
            ret += max(target[i] - target[i - 1], 0);
        }
        return ret;
    }
};
// @lc code=end