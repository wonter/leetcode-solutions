/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int prefix_sum[n];
        int suffix_sum[n];

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                prefix_sum[i] = cardPoints[i];
            } else {
                prefix_sum[i] = prefix_sum[i - 1] + cardPoints[i];
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                suffix_sum[i] = cardPoints[i];
            } else {
                suffix_sum[i] = suffix_sum[i + 1] + cardPoints[i];
            }
        }

        int ret = 0;
        for (int i = 0; i <= k; ++i) {
            int sum = 0;
            if (i != 0) {
                sum += prefix_sum[i - 1];
            }
            if (i != k) {
                sum += suffix_sum[n - k + i];
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};
// @lc code=end

