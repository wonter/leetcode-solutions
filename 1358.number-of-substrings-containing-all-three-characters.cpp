/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int len = s.size();
        int slow = 0;
        int fast = 0;
        int counter[3] = { 0 };
        int ret = 0;
        ++counter[s[fast] - 'a'];
        while ((counter[0] > 0 && counter[1] > 0 && counter[2] > 0) || fast < len) {
            while ((counter[0] == 0 || counter[1] == 0 || counter[2] == 0) && fast < len) {
                ++fast;
                if (fast < len) {
                    ++counter[s[fast] - 'a'];
                }
            }

            if (counter[0] > 0 && counter[1] > 0 && counter[2] > 0) {
                ret += len - fast; 
                --counter[s[slow] - 'a'];
                ++slow;
            }
        }
        return ret;
    }
};
// @lc code=end
