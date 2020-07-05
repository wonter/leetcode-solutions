/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int height[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    height[i][j] = 0;
                    continue;
                }

                if (mat[i][j] == 1) {
                    if (i == 0) {
                        height[i][j] = 1;
                    } else {
                        height[i][j] = height[i - 1][j] + 1;
                    }
                }
            }
        }


        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         cout << height[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int h = 1; h <= n; ++h) {
                int continuous = 0;
                for (int j = 0; j < m; ++j) {
                    if (height[i][j] >= h) {
                        continuous += 1;
                    } else {
                        ret += continuous * (continuous + 1) / 2;
                        continuous = 0;
                    }
                }
                ret += continuous * (continuous + 1) / 2;
            }
        }

        return ret;
    }
};
// @lc code=end

