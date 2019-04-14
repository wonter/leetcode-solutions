/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 *
 * https://leetcode.com/problems/longest-arithmetic-sequence/description/
 *
 * algorithms
 * Medium (35.33%)
 * Total Accepted:    1.7K
 * Total Submissions: 4.8K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array A of integers, return the length of the longest arithmetic
 * subsequence in A.
 * 
 * Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0
 * <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is
 * arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length -
 * 1).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,12]
 * Output: 4
 * Explanation: 
 * The whole array is an arithmetic sequence with steps of length = 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,4,7,2,10]
 * Output: 3
 * Explanation: 
 * The longest arithmetic subsequence is [4,7,10].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation: 
 * The longest arithmetic subsequence is [20,15,10,5].
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 2000
 * 0 <= A[i] <= 10000
 * 
 * 
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        static int dp[2001][20010];

        memset(dp, 0, sizeof(dp));

        int n = A.size();
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int sub = A[i] - A[j];
                if (sub < 0) {
                    sub = 10000 - sub;
                }
                
                dp[i][sub] = dp[j][sub] + 1;
                ret = max(ret, dp[i][sub]);
            }
        }
        return ret + 1;
    }
};

