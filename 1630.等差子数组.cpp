/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ret;
        for (int i = 0; i < m; ++i) {
            int left = l[i];
            int right = r[i];
            // cout << left << " " << right << endl;
            vector<int> new_nums(nums.begin() + left, nums.begin() + right + 1);
            sort(new_nums.begin(), new_nums.end());
            ret.emplace_back(check(new_nums));
        }
        return ret;
    }

    bool check(const vector<int> vec) {
        if (vec.size() <= 1) {
            return true;
        }

        int d = vec[1] - vec[0];
        for (int i = 2; i < vec.size(); ++i) {
            if (vec[i] - vec[i - 1] != d) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

