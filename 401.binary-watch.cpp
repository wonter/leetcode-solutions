/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.48%)
 * Likes:    385
 * Dislikes: 645
 * Total Accepted:    66K
 * Total Submissions: 145K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count_one(i) + count_one(j) == num) {
                    string time;
                    time = to_string(i) + ":";
                    if (j < 10) {
                        time += "0";
                    }
                    time += to_string(j);
                    ret.emplace_back(time);
                }
            }
        }
        return ret;
    }

private:
    int count_one(int num) {
        int ret = 0;
        while (num) {
            num = num & (num - 1);
            ret++;
        }
        return ret;
    }
};
