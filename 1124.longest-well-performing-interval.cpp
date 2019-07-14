/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 *
 * https://leetcode.com/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (20.23%)
 * Likes:    31
 * Dislikes: 28
 * Total Accepted:    1.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * We are given hours, a list of the number of hours worked per day for a given
 * employee.
 * 
 * A day is considered to be a tiring day if and only if the number of hours
 * worked is (strictly) greater than 8.
 * 
 * A well-performing interval is an interval of days for which the number of
 * tiring days is strictly larger than the number of non-tiring days.
 * 
 * Return the length of the longest well-performing interval.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hours = [9,9,6,0,6,6,9]
 * Output: 3
 * Explanation: The longest well-performing interval is [9,9,6].
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hours.length <= 10000
 * 0 <= hours[i] <= 16
 * 
 */
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for (int& hour : hours) {
            if (hour > 8) {
                hour = 1;
            } else {
                hour = -1;
            }
        }

        vector<int> sum(hours.size());
        vector<int> minimum(hours.size());
        for (int i = 0; i < hours.size(); i++) {
            if (i == 0) {
                sum[i] = hours[i];
                minimum[i] = sum[i];
            } else {
                sum[i] = sum[i - 1] + hours[i];
                minimum[i] = min(minimum[i - 1], sum[i]);
            }
        }

        int ret = 0;
        for (int i = 0; i < hours.size(); ++i) {
            if (sum[i] > 0) {
                ret = i + 1;
                continue;
            }

            int need = sum[i];
            int l = 0;
            int r = i;
            while (l < r) {
                int mid = (l + r) / 2;
                if (minimum[mid] < need) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            ret = max(ret, i - l);
        }

        return ret;
    }
};
