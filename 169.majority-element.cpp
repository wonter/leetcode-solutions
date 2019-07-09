/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (52.59%)
 * Likes:    1759
 * Dislikes: 150
 * Total Accepted:    400.1K
 * Total Submissions: 752.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int counter = 0;
        for (int num : nums) {
            if (counter == 0) {
                majority = num;
            } 

            if (num == majority) {
                ++counter;
            } else {
                --counter;
            }
        }
        return majority;
    }
};

