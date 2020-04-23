#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();

        long long f = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            f = f + i * A[i];
            sum += A[i];
        }

        long long ans = f;
        for (int i = 0; i < n; ++i) {
            f = f + sum - static_cast<long long>(n) * A[n - i - 1];
            ans = max(ans, f);
        }

        return ans;
    }
};
// @lc code=end

