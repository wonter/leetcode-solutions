/*
 * @lc app=leetcode id=1471 lang=cpp
 *
 * [1471] The k Strongest Values in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), [](int x, int y) {
            return x < y;
        });

        int n = arr.size();
        int median = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [median](int x, int y) {
            int xx = abs(x - median);
            int yy = abs(y - median);
            if (xx == yy) {
                return x > y;
            }
            return xx > yy;
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
// @lc code=end

