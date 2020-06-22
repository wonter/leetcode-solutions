#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1476 lang=cpp
 *
 * [1476] Subrectangle Queries
 */

// @lc code=start
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : _rectangle(rectangle) {
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int row = row1; row <= row2; ++row) {
            for (int col = col1; col <= col2; ++col) {
                _rectangle[row][col] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return _rectangle[row][col];
    }

private:
    vector<vector<int>> _rectangle;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end

