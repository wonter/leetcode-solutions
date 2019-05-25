/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i || j == 0) {
                    row[j] = 1;
                } else {
                    row[j] += row[j - 1];
                }
            }
        }
        return row;
    }
};

