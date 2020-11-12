/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int next_odd = 1;
        for (int i = 0; i < A.size(); i += 2) {
            while (A[i] & 1) {
                swap(A[i], A[next_odd]);
                next_odd += 2;
            }
        }
        return A;
    }
};
// @lc code=end

