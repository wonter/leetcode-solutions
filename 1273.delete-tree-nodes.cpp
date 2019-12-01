class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int root = -1;
        vector<vector<int>> child(nodes, vector<int>{});
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == -1) {
                root = i;
                continue;
            }
            child[parent[i]].emplace_back(i);
        }

        vector<int> sum(nodes, 0);
        return dfs(root, child, value, sum);
    }

    int dfs(int root, const vector<vector<int>>& child, const vector<int>& value, vector<int>& sum) {
        int counter = 1;
        sum[root] = value[root];
        for (size_t i = 0; i < child[root].size(); ++i) {
            counter += dfs(child[root][i], child, value, sum);
            sum[root] += sum[child[root][i]];
        }

        if (sum[root] == 0) {
            return 0;
        }
        return counter;
    }
};