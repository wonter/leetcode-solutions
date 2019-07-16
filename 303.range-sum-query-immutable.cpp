/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (38.63%)
 * Likes:    488
 * Dislikes: 800
 * Total Accepted:    144.4K
 * Total Submissions: 373.4K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
            _prefix_sum.emplace_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return _prefix_sum[j];
        }
        return _prefix_sum[j] - _prefix_sum[i - 1];
    }
private:
    vector<int> _prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

