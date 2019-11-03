/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A subarray is called nice
 * if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum[nums.size() + 1];
        memset(sum, 0, sizeof(sum));

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        unordered_map<int, int> counter;
        counter[0] = 1;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (nums[i - 1] & 1 ? 1 : 0);
            counter[sum[i]]++;
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            ret += counter[sum[i] - k];
        }
        return ret;
    }
};
// @lc code=end

