/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> undirected_next(n);
        vector<unordered_set<int>> directed_next(n);
        for (vector<int>& vec : connections) {
            undirected_next[vec[0]].emplace_back(vec[1]);
            undirected_next[vec[1]].emplace_back(vec[0]);
            directed_next[vec[0]].insert(vec[1]);
        }

        int ret = 0;
        queue<int> que;
        vector<int> vis(n);
        que.push(0);
        vis[0] = true;
        while (!que.empty()) {
            int front = que.front();
            que.pop();

            for (int i = 0; i < undirected_next[front].size(); ++i) {
                int nxt = undirected_next[front][i];
                if (vis[nxt]) {
                    continue;
                }

                if (directed_next[front].find(nxt) != directed_next[front].end()) {
                    ++ret;
                }
                que.push(nxt);
                vis[nxt] = true;
            }
        }
        return ret;
    }
};
// @lc code=end

