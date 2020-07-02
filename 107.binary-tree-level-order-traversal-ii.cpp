/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return std::move(ret);
        }
        
        queue<TreeNode*> que;
        vector<int> current_level;
        
        que.push(root);
        que.push(nullptr);
        while (!que.empty()) {
            TreeNode* front = que.front();
            que.pop();
            
            if (front == nullptr) {
                ret.emplace_back(std::move(current_level));
                current_level.clear();
                
                if (!que.empty()) {
                    que.push(nullptr);
                    continue;
                } else {
                    break;  
                }
            }
            
            current_level.emplace_back(front->val);
            
            if (front->left) {
                que.push(front->left);
            }
            if (front->right) {
                que.push(front->right);
            }
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

