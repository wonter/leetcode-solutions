/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (37.31%)
 * Likes:    786
 * Dislikes: 226
 * Total Accepted:    211.4K
 * Total Submissions: 561.5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> serialize_s;
        vector<int> serialize_t;

        {
            int vis[256] = {0};
            int counter = 0;
            for (char ch : s) {
                if (vis[ch] == 0) {
                    vis[ch] = ++counter;
                }

                serialize_s.emplace_back(vis[ch]);
            }
        }

        {
            int vis[256] = {0};
            int counter = 0;
            for (char ch : t) {
                if (vis[ch] == 0) {
                    vis[ch] = ++counter;
                }

                serialize_t.emplace_back(vis[ch]);
            }
        }

        return serialize_s == serialize_t;
    }
};

