/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> coordinates;
        coordinates.reserve(R * C);

        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                coordinates.emplace_back(vector<int>{r, c});
            }
        }

        sort(coordinates.begin(), coordinates.end(), bind(&Solution::doCompare, this, r0, c0, placeholders::_1, placeholders::_2));

        return coordinates;
    }

private:
    bool doCompare(int r0, int c0, const vector<int>& lhs, const vector<int>& rhs) {
        return distance(r0, c0, lhs[0], lhs[1]) < distance(r0, c0, rhs[0], rhs[1]);
    }
    
    int distance(int r1, int c1, int r2, int c2) {
        return abs(r1 - r2) + abs(c1 - c2);
    }
};

