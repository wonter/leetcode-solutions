/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.22%)
 * Total Accepted:    239.8K
 * Total Submissions: 530.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            triangle.emplace_back(vector<int>{});

            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    triangle[i].emplace_back(1);
                } else {
                    triangle[i].emplace_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
                }
            }
        }

        return triangle;
    }
};

