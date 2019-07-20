/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (55.41%)
 * Likes:    430
 * Dislikes: 844
 * Total Accepted:    233.3K
 * Total Submissions: 420.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ret;

        unordered_set<int> vis;
        for (int num : nums1) {
            vis.emplace(num);
        }

        for (int num : nums2) {
            if (vis.find(num) != vis.end()) {
                ret.emplace(num);
            }
        }

        return vector<int>(ret.begin(), ret.end());
    }
};

