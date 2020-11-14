/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
using IntPair = pair<int, int>;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        vector<IntPair> tmp;
        for (auto& pair : counter) {
            tmp.emplace_back(IntPair{pair.first, pair.second});
        }
        sort(tmp.begin(), tmp.end(), [](const IntPair& lhs, const IntPair& rhs) {
            if (lhs.second == rhs.second) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        });

        vector<int> ans;
        for (auto& pair : tmp) {
            for (int i = 0; i < pair.second; ++i) {
                ans.emplace_back(pair.first);
            }
        }
        return ans;
    }
};
// @lc code=end

