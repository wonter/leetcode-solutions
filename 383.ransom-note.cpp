/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (50.24%)
 * Likes:    334
 * Dislikes: 127
 * Total Accepted:    117.5K
 * Total Submissions: 233.7K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;
        for (char ch : magazine) {
            counter[ch]++;
        }

        for (char ch : ransomNote) {
            if (counter[ch] <= 0) {
                return false;
            }

            counter[ch]--;
        }

        return true;
    }
};