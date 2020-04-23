#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            const string& from = equations[i][0];
            const string& to = equations[i][1];
            double weight = values[i];
            edges.emplace_back(Edge{from, to, weight});
            arcs_map[from].emplace_back(edges.size() - 1);
            edges.emplace_back(Edge{to, from, 1.0 / weight});
            arcs_map[to].emplace_back(edges.size() - 1);
        }

        vector<double> ret;
        for (const vector<string>& query : queries) {
            const string& from = query[0];
            const string& to = query[1];

            if (arcs_map.find(from) == arcs_map.end()) {
                ret.emplace_back(-1.0);
                continue;
            }

            queue<pair<string, double>> que;
            unordered_set<string> vis;
            que.push({from, 1.0});
            vis.insert(from);
            double ans = -1.0;
            while (!que.empty()) {
                pair<string, double> front = que.front();
                que.pop();

                if (front.first == to) {
                    ans = front.second;
                    break;
                }

                auto it = arcs_map.find(front.first);
                if (it == arcs_map.end()) {
                    continue;
                }

                const vector<int>& arcs = it->second;
                for (int i = 0; i < arcs.size(); ++i) {
                    const Edge& edge = edges[arcs[i]];
                    if (vis.find(edge.to) != vis.end()) {
                        continue;
                    }

                    que.push({edge.to, front.second * edge.weight});
                    vis.insert(edge.to);
                }
            }
            ret.emplace_back(ans);
        }
        return ret;
    }

private:
    struct Edge {
        string from;
        string to;
        double weight;
    };

    unordered_map<string, vector<int>> arcs_map;
    vector<Edge> edges;
};
// @lc code=end

