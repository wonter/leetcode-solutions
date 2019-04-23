/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(maxSumTwoNoOverlapOrdered(A, L, M), maxSumTwoNoOverlapOrdered(A, M, L));
    }

private:
    int maxSumTwoNoOverlapOrdered(const vector<int>& A, int L, int M) {
        int n = A.size();
        assert(n >= L && n >= M);

        int maxSum = 0;

        int sum = 0;
        for (int i = 0; i < L - 1; ++i) {
            sum += A[i];
        }
        for (int i = L - 1; i < n; ++i) {
            sum += A[i];
            if (i + 1 + M <= n) {
                maxSum = max(maxSum, sum + maxSubarray(A, i + 1, M));
                sum -= A[i - L + 1];
            } else {
                break;
            }
        }

        return maxSum;
    }

    int maxSubarray(const vector<int>& A, int s, int M) {
        int n = A.size();
        assert(s + M <= n);

        int maxSum = 0;
        int sum = 0;
        for (int i = s; i < s + M - 1; ++i) {
            sum += A[i];
        }

        for (int i = s + M - 1; i < n; ++i) {
            sum += A[i];            
            maxSum = max(maxSum, sum);
            sum -= A[i - M + 1];
        }

        return maxSum;
    }
};