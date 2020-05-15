/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long ret = 0;
        vector<int> temp(nums.size(), 0);
        merge_sort(nums, 0, nums.size() - 1, temp, ret);
        return ret;
    }

private:
    void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp, long long& ret) {
        if (l >= r) {
            return;
        }

        int mid = (l + r) / 2;
        merge_sort(nums, l, mid, temp, ret);
        merge_sort(nums, mid + 1, r, temp, ret);

        int i = l;
        int j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] > static_cast<long long>(nums[j]) * 2) {
                ret += mid - i + 1;
                ++j;
            } else {
                ++i;
            }
        }

        int idx = 0;
        i = l;
        j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[idx++] = nums[i];
                ++i;
            } else {
                temp[idx++] = nums[j];
                ++j;
            }
        }
        while (i <= mid) {
            temp[idx++] = nums[i];
            ++i;
        }
        while (j <= r) {
            temp[idx++] = nums[j];
            ++j;
        }
        for (int i = l; i <= r; ++i) {
            nums[i] = temp[i - l];
        }
    }
};
// @lc code=end
