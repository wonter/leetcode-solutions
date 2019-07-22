/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.30%)
 * Likes:    559
 * Dislikes: 57
 * Total Accepted:    101.9K
 * Total Submissions: 210.9K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;
        for (char ch : s) {
            counter[ch]++;
        }

        int ret = 0;
        for (auto& pair : counter) {
            int contribute = (pair.second) / 2 * 2;
            ret += contribute;
            pair.second -= contribute;
        }

        for (const auto& pair : counter) {
            if (pair.second % 2 != 0) {
                ++ret;
                break;
            }
        }

        return ret;
    }
};

