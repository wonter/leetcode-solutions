/*
 * @lc app=leetcode id=1583 lang=cpp
 *
 * [1583] Count Unhappy Friends
 */

// @lc code=start
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int prefers[550][550];
        memset(prefers, -1, sizeof(prefers));
        for (int i = 0; i < preferences.size(); ++i) {
            for (int j = 0; j < preferences[i].size(); ++j) {
                prefers[i][preferences[i][j]] = n - j;
            }
        }

        set<int> ans;
        for (int i = 0; i < pairs.size(); ++i) {
            for (int j = 0; j < pairs.size(); ++j) {
                if (i == j) {
                    continue;
                }

                if (unhappy(pairs[i][0], pairs[i][1], pairs[j][0], pairs[j][1], prefers)) {
                    ans.insert(pairs[i][0]);
                } else if (unhappy(pairs[i][0], pairs[i][1], pairs[j][1], pairs[j][0], prefers)) {
                    ans.insert(pairs[i][0]);
                }

                if (unhappy(pairs[i][1], pairs[i][0], pairs[j][0], pairs[j][1], prefers)) {
                    ans.insert(pairs[i][1]);
                } else if (unhappy(pairs[i][1], pairs[i][0], pairs[j][1], pairs[j][0], prefers)) {
                    ans.insert(pairs[i][1]);
                }

                if (unhappy(pairs[j][0], pairs[j][1], pairs[i][0], pairs[i][1], prefers)) {
                    ans.insert(pairs[j][0]);
                } else if (unhappy(pairs[j][0], pairs[j][1], pairs[i][1], pairs[i][0], prefers)) {
                    ans.insert(pairs[j][0]);
                }

                if (unhappy(pairs[j][1], pairs[j][0], pairs[i][0], pairs[i][1], prefers)) {
                    ans.insert(pairs[j][1]);
                } else if (unhappy(pairs[j][1], pairs[j][0], pairs[i][1], pairs[i][0], prefers)) {
                    ans.insert(pairs[j][1]);
                }
            }
        }

        return ans.size();
    }

private:
    bool unhappy(int x, int y, int u, int v, int prefers[550][550]) {
        if (prefers[x][u] > prefers[x][y] && prefers[u][x] > prefers[u][v]) {
            return true;
        }
        return false;
    }
};
// @lc code=end

