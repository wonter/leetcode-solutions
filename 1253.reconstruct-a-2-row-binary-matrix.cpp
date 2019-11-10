/*
 * @lc app=leetcode id=1253 lang=cpp
 *
 * [1253] Reconstruct a 2-Row Binary Matrix
 *
 * https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/
 *
 * algorithms
 * Medium (33.13%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 6.5K
 * Testcase Example:  '2\n1\n[1,1,1]'
 *
 * Given the following details of a matrix with n columns and 2 rows :
 * 
 * 
 * The matrix is a binary matrix, which means each element in the matrix can be
 * 0 or 1.
 * The sum of elements of the 0-th(upper) row is given as upper.
 * The sum of elements of the 1-st(lower) row is given as lower.
 * The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum
 * is given as an integer array with length n.
 * 
 * 
 * Your task is to reconstruct the matrix with upper, lower and colsum.
 * 
 * Return it as a 2-D integer array.
 * 
 * If there are more than one valid solution, any of them will be accepted.
 * 
 * If no valid solution exists, return an empty 2-D array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: upper = 2, lower = 1, colsum = [1,1,1]
 * Output: [[1,1,0],[0,0,1]]
 * Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct
 * answers.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: upper = 2, lower = 3, colsum = [2,2,1,1]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
 * Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= colsum.length <= 10^5
 * 0 <= upper, lower <= colsum.length
 * 0 <= colsum[i] <= 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ret(2, vector<int>(colsum.size(), 0));

        for (size_t i = 0; i < colsum.size(); ++i) {
            if (colsum[i] != 2) {
                continue;
            }

            ret[0][i] = ret[1][i] = 1;
            --upper;
            --lower;
        }

        for (size_t i = 0; i < colsum.size(); ++i) {
            if (colsum[i] != 1) {
                continue;
            }

            if (upper > 0) {
                ret[0][i] = 1;
                --upper;
            } else if (lower > 0) {
                ret[1][i] = 1;
                --lower;
            } else {
                return {};
            }
        }

        if (upper == 0 && lower == 0) {
            return ret;
        }

        return {};
    }
};
// @lc code=end

