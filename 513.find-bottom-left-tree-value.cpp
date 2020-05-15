/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// @lc code=start
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
    int findBottomLeftValue(TreeNode* root) {
        int ret = root->val;
        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        while (!que.empty()) {
            TreeNode* front = que.front();
            que.pop();

            if (front == nullptr) {
                if (!que.empty()) {
                    que.push(nullptr);
                    ret = que.front()->val;
                }
                continue;
            }

            if (front->left) {
                que.push(front->left);
            }
            
            if (front->right) {
                que.push(front->right);
            }
        }
        return ret;
    }
};
// @lc code=end

