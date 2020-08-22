/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> indegree;
        for (const vector<int>& edge : edges) {
            indegree[edge[1]]++;
        }
        
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                ret.emplace_back(i);
            }
        }
        
        return ret;
    }
};
// @lc code=end

