/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0;
        int n = customers.size();
        
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        int ret = sum;
        for (int i = 0; i <= n - X; ++i) {
            int new_ret = sum;
            for (int j = 0; j < X; ++j) {
                if (grumpy[i + j] == 1) {
                    new_ret += customers[i + j];
                }
            }
            ret = max(ret, new_ret);

        }
        
        return ret;
    }
};

