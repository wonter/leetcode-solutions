/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.32%)
 * Likes:    1078
 * Dislikes: 81
 * Total Accepted:    289.7K
 * Total Submissions: 575.3K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }

        int counter[26];
        memset(counter, 0, sizeof(counter));

        for (int i = s.size() - 1; i >= 0; --i) {
            counter[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (counter[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

