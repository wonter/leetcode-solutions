/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        int odd = 0;
        int even = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            sum += arr[i - 1];

            if (sum & 1) {
                ans = (ans + even + 1) % 1000000007;
                odd += 1;
            } else {
                ans = (ans + odd) % 1000000007;
                even += 1;
            }
        }

        return ans;
    }
};
// @lc code=end
