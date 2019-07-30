/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (29.19%)
 * Likes:    398
 * Dislikes: 736
 * Total Accepted:    98.8K
 * Total Submissions: 337.5K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        long long max_num = -10000000000000ll;
        long long middle_num = -10000000000000ll;
        long long min_num = -10000000000000ll;

        for (int num : nums) {
            if (num == max_num) {
                continue;
            }
            if (num == middle_num) {
                continue;
            }

            if (num > max_num) {
                min_num = middle_num;
                middle_num = max_num;
                max_num = num;
            } else if (num > middle_num) {
                min_num = middle_num;
                middle_num = num;
            } else if (num > min_num) {
                min_num = num;
            }
        }

        if (min_num == -10000000000000ll) {
            return max_num;
        } else {
            return min_num;
        }
    }
};

