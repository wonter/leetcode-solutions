/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int x, int y) {
            int x_one = count_one(x);
            int y_one = count_one(y);
            if (x_one == y_one) {
                return x < y;
            }
            return x_one < y_one;
        });
        return arr;
    }

private:
    int count_one(int x) {
        int ret = 0;
        while (x != 0) {
            ret += x & 1;
            x >>= 1;
        }
        return ret;
    }
};
// @lc code=end

