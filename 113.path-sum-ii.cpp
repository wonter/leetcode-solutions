/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (40.01%)
 * Total Accepted:    221.9K
 * Total Submissions: 554.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> total_path;
        vector<int> single_path;

        pathSum(root, sum, single_path, total_path);

        return total_path;
    }

private:
    void pathSum(TreeNode* root, int sum, vector<int>& single_path, vector<vector<int>>& total_path) {
        if (root == nullptr) {
            // empty tree
            return;
        }

        single_path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            // leaf
            if (sum == root->val) {
                total_path.emplace_back(single_path);
            }
        }

        if (root->left) {
            // has left child
            pathSum(root->left, sum - root->val, single_path, total_path);
        }

        if (root->right) {
            // has right child
            pathSum(root->right, sum - root->val, single_path, total_path);
        }

        single_path.pop_back();
    }
};