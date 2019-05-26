/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int min_num = INT_MAX;
        int n = A.size();
        for (int i = n - 1; i >= 0; --i) {
            if (min_num < A[i]) {
                int max_num_idx = -1;
                for (int j = i + 1; j < n; ++j) {
                    if (A[j] < A[i] && (max_num_idx == -1 || A[max_num_idx] < A[j])) {
                        max_num_idx = j;
                    }
                }
                assert(max_num_idx != -1);
                swap(A[i], A[max_num_idx]);
                break;
            }
            min_num = min(min_num, A[i]);
        }
        return A;
    }
};

