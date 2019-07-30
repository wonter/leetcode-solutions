/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (59.94%)
 * Likes:    280
 * Dislikes: 33
 * Total Accepted:    39.4K
 * Total Submissions: 65.4K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }

        vector<int> level;
        queue<Node*> que;
        que.push(root);
        que.push(nullptr);
        while (!que.empty()) {
            Node* front = que.front();
            que.pop();
            if (front == nullptr) {
                ret.emplace_back(level);
                level.clear();
                if (que.empty()) {
                    break;
                }
                que.push(nullptr);
                continue;
            }

            level.emplace_back(front->val);
            for (Node* node : front->children) {
                que.push(node);
            }
        }

        return ret;
    }
};

