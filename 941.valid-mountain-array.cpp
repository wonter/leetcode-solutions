/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return false;
        }

        bool rise = true;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] == A[i + 1]) {
                return false;
            }

            if (rise) {
                if (A[i] < A[i + 1]) {
                    continue;
                } else if (i == 0) {
                    return false;
                } else {
                    rise = false;
                }
            } else {
                if (A[i] > A[i + 1]) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return rise == false;
    }
};
// @lc code=end

