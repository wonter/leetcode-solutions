/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int alice = piles.size() - 1;
        int bob = 0;
        int me = alice - 1;
        int ret = 0;
        while (bob < me && me < alice) {
            ret += piles[me];
            
            ++bob;
            alice = me - 1;
            me = alice - 1;
        }
        return ret;
    }
};
// @lc code=end

