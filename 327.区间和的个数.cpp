/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ret = 0;

        vector<long long> prefix_sum(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                prefix_sum[i] = nums[i];
            } else {
                prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            }

            if (prefix_sum[i] >= lower && prefix_sum[i] <= upper) {
                ++ret;
            }
        }

        return ret + countRangeSum(prefix_sum, 0, static_cast<int>(prefix_sum.size()) - 1, lower, upper);
    }

    int countRangeSum(vector<long long>& nums, int l, int r, int lower, int upper) {
        if (l >= r) {
            return 0;
        }

        int ret = 0;

        int mid = (l + r) / 2;
        ret += countRangeSum(nums, l, mid, lower, upper);
        ret += countRangeSum(nums, mid + 1, r, lower, upper);

        int left = mid + 1;
        int right = mid + 1;
        for (int i = l; i <= mid; ++i) {
            while (left <= r && nums[left] - nums[i] < lower) {
                ++left;
            }
            while (right <= r && nums[right] - nums[i] <= upper) {
                ++right;
            }
            ret += right - left;
        }

        vector<long long> tmp;
        int pos1 = l;
        int pos2 = mid + 1;
        while (pos1 <= mid && pos2 <= r) {
            if (nums[pos1] < nums[pos2]) {
                tmp.emplace_back(nums[pos1]);
                ++pos1;
            } else {
                tmp.emplace_back(nums[pos2]);
                ++pos2;
            }
        }
        while (pos1 <= mid) {
            tmp.emplace_back(nums[pos1]);
            ++pos1;
        }
        while (pos2 <= r) {
            tmp.emplace_back(nums[pos2]);
            ++pos2;
        }
        for (int i = l; i <= r; ++i) {
            nums[i] = tmp[i - l];
        }

        return ret;
    }
};
// @lc code=end

