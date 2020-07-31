/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int distance, int& ans) {
        if (root == nullptr) {
            return;
        }

        int left_depth[1024] = {};
        int right_depth[1024] = {};

        dfs(root->left, 1, left_depth);
        dfs(root->right, 1, right_depth);


        for (int i = 1; i < 1024; ++i) {
            right_depth[i] += right_depth[i - 1];
        }
        for (int i = 1; i < distance; ++i) {
            ans += left_depth[i] * right_depth[distance - i];
        }

        dfs(root->left, distance, ans);
        dfs(root->right, distance, ans);
    }

    void dfs(TreeNode* root, int depth, int* depths) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            depths[depth] += 1;
        }

        dfs(root->left, depth + 1, depths);
        dfs(root->right, depth + 1, depths);
    }
};
// @lc code=end
