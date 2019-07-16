/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.25%)
 * Likes:    672
 * Dislikes: 82
 * Total Accepted:    146.2K
 * Total Submissions: 414.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream sstrm(str);

        size_t i = 0;
        string word;
        unordered_map<char, string> pattern_idx;
        unordered_map<string, char> word_idx;
        while (sstrm >> word) {
            if (i == pattern.size()) {
                return false;
            }

            if (!word_idx[word] && pattern_idx[pattern[i]].empty()) {
                word_idx[word] = pattern[i];
                pattern_idx[pattern[i]] = word;
            } else if (word_idx[word] != pattern[i] || pattern_idx[pattern[i]] != word) {
                return false;
            }

            i++;
        }

        return i == pattern.size();
    }
};

