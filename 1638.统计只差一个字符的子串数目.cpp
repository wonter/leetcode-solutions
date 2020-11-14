/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        vector<string> sub_s[110];
        vector<string> sub_t[110];

        int n = s.size();
        int m = t.size();
        for (int i = 0; i < n; ++i) {
            string tmp;
            for (int j = i; j < n; ++j) {
                tmp.push_back(s[j]);
                sub_s[tmp.size()].emplace_back(tmp);
            }
        }
        for (int i = 0; i < m; ++i) {
            string tmp;
            for (int j = i; j < m; ++j) {
                tmp.push_back(t[j]);
                sub_t[tmp.size()].emplace_back(tmp);
            }
        }

        int ans = 0;
        for (int len = 1; len <= 100; ++len) {
            for (const string& str : sub_s[len]) {
                // cout << "find " << str << " " << find(sub_t[len], str) << endl;
                ans += find(sub_t[len], str);
            }
        }
        return ans;
    }

    int find(const vector<string>& sub_t, const string& s) {
        int ret = 0;
        int n = s.size();
        for (const string& t : sub_t) {
            int diff = 0;
            for (int i = 0; i < n && diff <= 1; ++i) {
                if (s[i] != t[i]) {
                    ++diff;
                }
            }
            if (diff == 1) {
                ++ret;
            }
        }
        return ret;
    }
};
// @lc code=end

