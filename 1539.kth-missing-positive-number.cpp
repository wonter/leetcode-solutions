/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miss = 0;
        int j = 0;
        for (int i = 1; i <= 10000; ++i) {
            if (j < arr.size() && i == arr[j]) {
                ++j;
                continue;
            }

            ++miss;
            if (miss == k) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

