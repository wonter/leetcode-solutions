#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (j == 0) {
                    _multiply_parent[i][j] = parent[i];
                } else {
                    if (_multiply_parent[i][j - 1] == -1) {
                        _multiply_parent[i][j] = -1;
                    } else {
                        _multiply_parent[i][j] = _multiply_parent[_multiply_parent[i][j - 1]][j - 1];
                    }
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node == -1) {
            return node;
        }
        if (k == 0) {
            return node;
        }

        for (int i = 29; i >= 0; --i) {
            if (k & (1 << i)) {
                return getKthAncestor(_multiply_parent[node][i], k ^ (1 << i));
            }
        }

        return -1;
    }

private:
    int _multiply_parent[50040][30];
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

