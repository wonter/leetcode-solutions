/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (size_t i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                filtered.push_back(tolower(s[i]));
            }
        }

        for (int i = 0, j = static_cast<int>(filtered.size()) - 1; i < j; ++i, --j) {
            if (filtered[i] != filtered[j]) {
                return false;
            }
        }

        return true;
    }
};

