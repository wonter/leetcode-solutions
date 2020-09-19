/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int len = 1; len <= arr.size(); len += 2) {
            for (int s = 0; s < arr.size(); ++s) {
                int e = s + len - 1;
                if (s < arr.size() && e < arr.size()) {
                    for (int k = s; k <= e; ++k) {
                        ans += arr[k];
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

