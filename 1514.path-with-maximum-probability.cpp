/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
struct Edge {
    int to;
    double value;
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m = edges.size();

        vector<Edge> e[n];
        for (int i = 0; i < m; ++i) {
            int from = edges[i][0];
            int to = edges[i][1];
            double value = succProb[i];

            e[from].emplace_back(Edge{to, value});
            e[to].emplace_back(Edge{from, value});
        }

        double mincost[n];
        priority_queue<pair<double, int>> que;
        fill(mincost, mincost + n, 0.0);
        mincost[start] = 1.0;
        que.push({mincost[start], start});
        while (!que.empty()) {
            pair<double, int> front = que.top();
            que.pop();

            if (fabs(front.first - mincost[front.second]) > 1e-6) {
                continue;
            }

            for (const Edge& edge : e[front.second]) {
                if (front.first * edge.value > mincost[edge.to]) {
                    mincost[edge.to] = front.first * edge.value;
                    que.push({mincost[edge.to], edge.to});
                }
            }
            cout << endl;
        }

        return mincost[end];
    }
};
// @lc code=end

