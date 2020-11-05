/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace_back(beginWord);
        int n = wordList.size();

        vector<vector<int>> edges(n);
        vector<bool> is_end(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (lad(wordList[i], wordList[j])) {
                    edges[i].emplace_back(j);
                    edges[j].emplace_back(i);
                }
            }

            if (wordList[i] == endWord) {
                is_end[i] = true;
            }
        }

        queue<int> que;
        vector<int> counter(n);
        que.push(n - 1);
        counter[n - 1] = 1;
        while (!que.empty()) {
            int from = que.front();
            que.pop();

            if (is_end[from]) {
                return counter[from];
            }

            for (int to : edges[from]) {
                if (counter[to] == 0) {
                    counter[to] = counter[from] + 1;
                    que.push(to);
                }
            }
        }

        return 0;
    }

    bool lad(const string& s1, const string& s2) {
        if (s1 == s2) {
            return false;
        }

        int n = s1.size();
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
            }
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
};
// @lc code=end

