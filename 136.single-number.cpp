/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x;
    }
};

