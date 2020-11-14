/*
 * @lc app=leetcode.cn id=1643 lang=cpp
 *
 * [1643] 第 K 条最小指令
 */

// @lc code=start
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int c[31][31] = {};
        for (int i = 0; i <= 30; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                }
            }
        }

        int v_num = destination[0];
        int h_num = destination[1];
        int length = v_num + h_num;
        --k;

        string ret;
        for (int i = 0; i < length; ++i) {
            if (v_num == 0) {
                ret.push_back('H');
                continue;
            }
            if (h_num == 0) {
                ret.push_back('V');
                continue;
            }
            if (k < c[length - i - 1][h_num - 1]) {
                ret.push_back('H');
                --h_num;
                continue;
            } else {
                ret.push_back('V');
                k -= c[length - i - 1][h_num - 1];
                --v_num;
                continue;
            }
        }
        return ret;
    }
};
// @lc code=end

