/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int counter[200] = {};
        
        int cur = rounds[0];
        for (int i = 1; i < rounds.size(); ++i) {
            while (cur != rounds[i]) {
                ++counter[cur];
                cur = cur % n + 1;
            }
        }
        ++counter[cur];
        
        int max_counter = *max_element(counter + 1, counter + 1 + n);
        vector<int> ret;
        for (int i = 1; i <= n; ++i) {
            if (counter[i] == max_counter) {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

