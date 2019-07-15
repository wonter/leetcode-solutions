/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (46.46%)
 * Likes:    933
 * Dislikes: 70
 * Total Accepted:    234.2K
 * Total Submissions: 503.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<TreeNode*>> paths = dfs(root);
        vector<string> ret;
        for (vector<TreeNode*>& path : paths) {
            reverse(path.begin(), path.end());

            string str;
            for (size_t i = 0; i < path.size(); ++i) {
                if (i == 0) {
                    str = str + to_string(path[i]->val);
                } else {
                    str = str + "->" + to_string(path[i]->val);
                }
            }

            if (!str.empty()) {
                ret.emplace_back(str);
            }
        }
        return ret;
    }

private:
    vector<vector<TreeNode*>> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {{root}};
        }

        vector<vector<TreeNode*>> left_paths;
        vector<vector<TreeNode*>> right_paths;
        left_paths = dfs(root->left);
        right_paths = dfs(root->right);

        vector<vector<TreeNode*>> paths;
        paths.insert(paths.end(), left_paths.begin(), left_paths.end());
        paths.insert(paths.end(), right_paths.begin(), right_paths.end());
        for (vector<TreeNode*>& path : paths) {
            path.emplace_back(root);
        }

        return paths;
    }
};

