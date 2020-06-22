#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1478 lang=cpp
 *
 * [1478] Allocate Mailboxes
 */

// @lc code=start
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = INT_MAX / 2;
            }
        }
        dp[0][0] = 0;

        for (int mailbox_num = 1; mailbox_num <= k; ++mailbox_num) {
            for (int i = 1; i <= n; ++i) {
                for (int j = i; j >= 1; --j) {
                    dp[i][mailbox_num] = min(dp[i][mailbox_num], calc(houses, j, i) + dp[j - 1][mailbox_num - 1]);
                }
            }
        }
        
        return dp[n][k];
    }

private:
    int calc(const vector<int>& houses, int s, int e) {
        --s;
        --e;

        int choose = houses[(s + e) / 2];
        int ret = 0;
        for (int i = s; i <= e; ++i) {
            ret += abs(houses[i] - choose);
        }
        return ret;
    }
};
// @lc code=end

