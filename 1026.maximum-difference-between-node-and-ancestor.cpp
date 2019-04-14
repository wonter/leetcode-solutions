/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (51.62%)
 * Total Accepted:    2.5K
 * Total Submissions: 4.8K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value V for which there
 * exists different nodes A and B where V = |A.val - B.val| and A is an
 * ancestor of B.
 * 
 * (A node A is an ancestor of B if either: any child of A is equal to B, or
 * any child of A is an ancestor of B.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: 
 * We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is between 2 and 5000.
 * Each node will have value between 0 and 100000.
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
    int maxAncestorDiff(TreeNode* root) {
        fill_maxmin_map(root, nullptr, nullptr);

        return find_answer(root);
    }

private:
    void fill_maxmin_map(TreeNode* root, TreeNode* max_node, TreeNode* min_node) {
        if (root == nullptr) {
            return;
        }

        max_ancestor[root] = max_node;
        min_ancestor[root] = min_node;

        if (max_node == nullptr || root->val > max_node->val) {
            max_node = root;
        }
        if (min_node == nullptr || root->val < min_node->val) {
            min_node = root;
        }

        fill_maxmin_map(root->left, max_node, min_node);
        fill_maxmin_map(root->right, max_node, min_node);
    }

    int find_answer(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int ret = 0;
        if (max_ancestor[node] != nullptr && min_ancestor[node] != nullptr) {
            ret = max(abs(node->val - max_ancestor[node]->val), abs(node->val - min_ancestor[node]->val));
        }

        ret = max(ret, find_answer(node->left));
        ret = max(ret, find_answer(node->right));

        return ret;
    }

    unordered_map<TreeNode*, TreeNode*>  max_ancestor;
    unordered_map<TreeNode*, TreeNode*>  min_ancestor;
};

