/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 || A[0] >= A[1]) {
            return false;
        }

        bool rise = true;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) {
                return false;
            }

            if (A[i] > A[i - 1]) {
                if (!rise) {
                    return false;
                }
            }

            if (A[i] < A[i - 1]) {
                if (rise) {
                    rise = false;
                }
            }
        }
        return !rise;
    }
};
// @lc code=end

