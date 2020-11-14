/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int weight[1001];
        memset(weight, 0x0f, sizeof(weight));
        for (size_t i = 0; i < arr2.size(); ++i) {
            weight[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [weight](int lhs, int rhs) {
            if (weight[lhs] == weight[rhs]) {
                return lhs < rhs;
            }
            return weight[lhs] < weight[rhs];
        });
        return arr1;
    }
};
// @lc code=end

