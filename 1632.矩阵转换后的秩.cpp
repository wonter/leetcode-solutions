/*
 * @lc app=leetcode.cn id=1632 lang=cpp
 *
 * [1632] 矩阵转换后的秩
 */

// @lc code=start
using IntPair = pair<int, int>;
class Solution {
public:
    Solution() {
        for (int i = 0; i < 250000; ++i) {
            parent[i] = i;
            edges[i].clear();
        }
        memset(in_degree, 0, sizeof(in_degree));
        memset(weight, 0, sizeof(weight));
        memset(rank, 0, sizeof(rank));
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            vector<IntPair> rows;
            for (int j = 0; j < m; ++j) {
                rows.emplace_back(IntPair{i, j});
            }
            sort(rows.begin(), rows.end(), [&matrix](const IntPair& lhs, const IntPair& rhs) {
                return matrix[lhs.first][lhs.second] < matrix[rhs.first][rhs.second];
            });

            IntPair pre = rows[0];
            for (int j = 1; j < rows.size(); ++j) {
                if (matrix[pre.first][pre.second] == matrix[rows[j].first][rows[j].second]) {
                    int x = pre.first * m + pre.second;
                    int y = rows[j].first * m + rows[j].second;
                    // cout << "merge " << x << " " << y << endl;
                    merge(x, y);
                } else {
                    int x = find_root(pre.first * m + pre.second);
                    int y = find_root(rows[j].first * m + rows[j].second);
                    edges[x].emplace_back(y);
                    // cout << x << "->" << y << endl;
                    ++in_degree[y];
                }
                pre = rows[j];
            }
        }

        for (int j = 0; j < m; ++j) {
            vector<IntPair> cols;
            for (int i = 0; i < n; ++i) {
                cols.emplace_back(IntPair{i, j});
            }
            sort(cols.begin(), cols.end(), [&matrix](const IntPair& lhs, const IntPair& rhs) {
                return matrix[lhs.first][lhs.second] < matrix[rhs.first][rhs.second];
            });

            IntPair pre = cols[0];
            for (int j = 1; j < cols.size(); ++j) {
                if (matrix[pre.first][pre.second] == matrix[cols[j].first][cols[j].second]) {
                    int x = pre.first * m + pre.second;
                    int y = cols[j].first * m + cols[j].second;
                    // cout << "merge " << x << " " << y << endl;
                    merge(x, y);
                } else {
                    int x = find_root(pre.first * m + pre.second);
                    int y = find_root(cols[j].first * m + cols[j].second);
                    edges[x].emplace_back(y);
                    // cout << x << "->" << y << endl;
                    ++in_degree[y];
                }
                pre = cols[j];
            }
        }

        queue<int> que;
        for (int i = 0; i < n * m; ++i) {
            if (find_root(i) != i) {
                continue;
            }

            if (in_degree[i] == 0 && !edges[i].empty()) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int front = que.front();
            que.pop();
            assert(in_degree[front] == 0);

            for (int next : edges[front]) {
                int root_next = find_root(next);
                --in_degree[root_next];
                if (in_degree[root_next] == 0) {
                    weight[root_next] = weight[front] + 1;
                    // cout << front << " unlock " << root_next << " weight[front]=" << weight[front] << " weight[root_next]=" << weight[root_next] << endl;
                    que.push(root_next);
                }
            }
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            for (int j = 0; j < m; ++j) {
                tmp.emplace_back(weight[find_root(i * m + j)] + 1);
            }
            ret.emplace_back(std::move(tmp));
        }

        return ret;
    }

    void merge(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);

        if(root_x == root_y) {
            return;
        }

        parent[root_y] = root_x;
        std::move(edges[root_y].begin(), edges[root_y].end(), std::back_inserter(edges[root_x]));
        in_degree[root_x] += in_degree[root_y];
    
    }

    int find_root(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find_root(parent[x]);
    }

private:
    vector<int> edges[250000];
    int in_degree[250000];
    int parent[250000];
    int weight[250000];
    int rank[250000];
};
// @lc code=end