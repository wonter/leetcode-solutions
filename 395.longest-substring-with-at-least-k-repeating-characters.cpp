#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }

private:
    int dfs(const string& s, int l, int r, int k) {
        int counter[26];
        fill(counter, counter + 26, -1);
        for (int i = l; i <= r; ++i) {
            if (counter[s[i] - 'a'] == -1) {
                counter[s[i] - 'a'] = 0;
            }
            ++counter[s[i] - 'a'];
        }

        bool fine = true;
        char bad_letter = 0;
        for (int i = 0; i < 26; ++i) {
            if (counter[i] == -1) {
                continue;
            }

            if (counter[i] < k) {
                bad_letter = 'a' + i;
                fine = false;
                break;
            }
        }
        if (fine) {
            return r - l + 1;
        }

        int left = l;
        int i = l;
        int ret = 0;
        for (i = l; i <= r; ++i) {
            if (s[i] == bad_letter) {
                if (l <= i - 1) {
                    ret = max(ret, dfs(s, l, i - 1, k));
                }
                l = i + 1;
            }
        }
        if (l <= i - 1) {
            ret = max(ret, dfs(s, l, i - 1, k));
        }
        return ret;
    }
};
// @lc code=end

