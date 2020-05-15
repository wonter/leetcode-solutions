/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        int max_value = INT_MIN;
        while (!que.empty()) {
            TreeNode *front = que.front();
            que.pop();

            if (front == nullptr) {
                if (!que.empty()) {
                    que.push(nullptr);
                }
                ret.emplace_back(max_value);
                max_value = INT_MIN;
                continue;
            }

            max_value = max(max_value, front->val);

            if (front->left) {
                que.push(front->left);
            }
            if (front->right) {
                que.push(front->right);
            }
        }
        return std::move(ret);
    }
};
// @lc code=end

