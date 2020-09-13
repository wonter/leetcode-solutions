/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Union {
public:
    Union() {
        for (int i = 0; i < 1100; ++i) {
            parent_[i] = i;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        parent_[root(x)] = root(y);
    }

private:
    int root(int x) {
        if (parent_[x] == x) {
            return x;
        }

        int r = root(parent_[x]);
        parent_[x] = r;
        return r;
    }

    int parent_[1100];
};

struct Edge {
    int from;
    int to;
    int dis;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                edges.push_back({i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }

        sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) {
            return lhs.dis < rhs.dis;
        });


        int ans = 0;
        Union u;
        for (const Edge& edge : edges) {
            if (u.same(edge.from, edge.to)) {
                continue;
            }

            u.merge(edge.from, edge.to);
            ans += edge.dis;
        }
        return ans;
    }
};
// @lc code=end

