/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
class Union {
public:
    Union(int n) : _parent(n, 0) {
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }
    ~Union() = default;

    void merge(int x, int y) {
        assert(x >= 0 && x < _parent.size());
        assert(y >= 0 && y < _parent.size());

        int rx = find_root(x);
        int ry = find_root(y);

        _parent[rx] = ry;
    }

    bool same_set(int x, int y) {
        assert(x >= 0 && x < _parent.size());
        assert(y >= 0 && y < _parent.size());

        return find_root(x) == find_root(y);
    }

private:
    int find_root(int x) {
        if (_parent[x] == x) {
            return x;
        }
        return _parent[x] = find_root(_parent[x]);
    }

    vector<int> _parent;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].emplace_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[2] < rhs[2];
        });

        int mst = calc_mst(n, edges, -1, -1);
        if (mst == INT_MAX) {
            return {{}, {}};
        }

        vector<int> vec1;
        vector<int> vec2;
        for (int i = 0; i < edges.size(); ++i) {
            int new_mst = mst;

            new_mst = calc_mst(n, edges, edges[i][3], -1);
            if (new_mst > mst) {
                vec1.emplace_back(edges[i][3]);
                continue;
            }

            new_mst = calc_mst(n, edges, -1, edges[i][3]);
            if (new_mst == mst) {
                vec2.emplace_back(edges[i][3]);
                continue;
            }
        }

        return {vec1, vec2};
    }

private:
    int calc_mst(int n, vector<vector<int>>& edges, int delete_idx, int choose_idx) {
        Union u(n);

        int m = edges.size();
        int nodes = 0;
        int total_weight = 0;

        for (const vector<int>& edge : edges) {
            if (edge[3] == choose_idx) {
                u.merge(edge[0], edge[1]);
                total_weight += edge[2];
                nodes = 2;
            }
        }

        for (const vector<int>& edge : edges) {
            if (edge[3] == delete_idx) {
                continue;
            }

            if (u.same_set(edge[0], edge[1])) {
                continue;
            }

            if (nodes == 0) {
                nodes = 2;
            } else {
                nodes += 1;
            }

            u.merge(edge[0], edge[1]);
            total_weight += edge[2];
        }

        if (nodes != n) {
            return INT_MAX;
        }

        return total_weight;
    }
};
// @lc code=end
