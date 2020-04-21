/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remain = 0;
        for (int byte : data) {
            if (remain == 0) {
                if ((byte & 0x80) == 0x00) {
                    remain = 0;
                } else if ((byte & 0xe0) == 0xc0) {
                    remain = 1;
                } else if ((byte & 0xf0) == 0xe0) {
                    remain = 2;
                } else if ((byte & 0xf8) == 0xf0) {
                    remain = 3;
                } else {
                    return false;
                }
            } else {
                if ((byte & 0xc0) != 0x80) {
                    return false;
                }
                --remain;
            }
        }
        return remain == 0;
    }
};
// @lc code=end
