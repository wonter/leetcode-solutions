/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int remove_size = n / 20;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i < remove_size) {
                continue;
            }

            if (n - i <= remove_size) {
                continue;
            }

            sum += arr[i];
        }
        return 1.0 * sum / (n - remove_size - remove_size);
    }
};
// @lc code=end

