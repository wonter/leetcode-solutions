/*
 * @lc app=leetcode id=1627 lang=cpp
 *
 * [1627] Graph Connectivity With Threshold
 */

// @lc code=start
class DSU {
public:
    DSU(int n) {
        for (int i = 1; i <= n; ++i) {
            parent_[i] = i;
        }
    }

    void merge(int x, int y) {
        parent_[find_root(x)] = find_root(y);
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

private:
    int find_root(int x) {
        if (parent_[x] == x) {
            return x;
        }
        return parent_[x] = find_root(parent_[x]);
    }

    int parent_[10050];
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i = 2; i <= n; ++i) {
            int t = sqrt(i);
            cout << i << endl;
            for (int j = 1; j <= t; ++j) {
                if (i % j != 0) {
                    continue;
                }

                if (j > threshold) {
                    dsu.merge(i, j);
                }

                int other = i / j;
                if (other > threshold) {
                    dsu.merge(i, other);
                }
            }
        }

        vector<bool> ans;
        for (vector<int>& query : queries) {
            ans.emplace_back(dsu.same(query[0], query[1]));
        }
        return ans;
    }
};
// @lc code=end

