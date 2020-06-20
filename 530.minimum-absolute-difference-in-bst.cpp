/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* root) {
        int pre_val = -1;
        int min_distance = INT_MAX;
        dfs(root, &pre_val, &min_distance);
        return min_distance;
    }

private:
    void dfs(TreeNode* root, int* pre_val, int* min_distance) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            dfs(root->left, pre_val, min_distance);
        }

        if (*pre_val != -1) {
            *min_distance = min(*min_distance, abs(root->val - *pre_val));
        }
        *pre_val = root->val;

        if (root->right) {
            dfs(root->right, pre_val, min_distance);
        }
    }
};
// @lc code=end

