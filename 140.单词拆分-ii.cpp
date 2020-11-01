/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
unordered_map<int, vector<string>> dp;
class Solution {
public:
    Solution() {
        dp.clear();
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        if (s.empty()) {
            ret.emplace_back("");
            return ret;
        }

        auto it = dp.find(s.size());
        if (it != dp.end()) {
            return it->second;
        }

        for (const string& word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                vector<string> tmp = wordBreak(s.substr(word.size()), wordDict);
                for (const string& s : tmp) {
                    if (s.empty()) {
                        ret.emplace_back(word);
                    } else {
                        ret.emplace_back(word + " " + s);
                    }
                }
            }
        }
        dp[s.size()] = ret;
        return ret;
    }
};
// @lc code=end

