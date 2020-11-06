/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int bit_a = count_bit(a);
            int bit_b = count_bit(b);
            if (bit_a == bit_b) {
                return a < b;
            }
            return bit_a < bit_b;
        });
        return arr;
    }

    int count_bit(int a) {
        int ret = 0;
        while (a) {
            ++ret;
            a = a & (a - 1);
        }
        return ret;
    }
};
// @lc code=end

