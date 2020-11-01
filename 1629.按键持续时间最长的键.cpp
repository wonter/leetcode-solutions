/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int pre = 0;
        int max_time = 0;
        char max_char = '\0';
        for (int i = 0; i < releaseTimes.size(); ++i) {
            int time = releaseTimes[i] - pre;
            pre = releaseTimes[i];

            if (time > max_time) {
                max_time = time;
                max_char = keysPressed[i];
            } else if (time == max_time && keysPressed[i] > max_char) {
                max_time = time;
                max_char = keysPressed[i];
            }
        }
        return max_char;
    }
};
// @lc code=end

