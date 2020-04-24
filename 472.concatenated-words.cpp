/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start

unordered_map<string, int> dp;

class Trie {
public:
    Trie() = default;
    ~Trie() = default;

    void insert(const string& data) {
        Node *node = &_root;
        for (char ch : data) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Node();
            }

            node = node->children[idx];
        }
        node->terminal = true;
    }

    bool break_up(const string& data) {
        return break_up_with_status(data) >= 2;
    }

private:
    struct Node {
        bool terminal = false;
        Node* children[26] = {};
    };

    int break_up_with_status(const string& data) {
        if (data.empty()) {
            return 0;
        }

        auto it = dp.find(data);
        if (it != dp.end()) {
            return it->second;
        }

        int ans = -1;
        Node *node = &_root;
        for (int i = 0; i < data.size(); ++i) {
            int idx = data[i] - 'a';
            if (node->children[idx] == nullptr) {
                break;
            }

            node = node->children[idx];
            if (node->terminal) {
                int remain = break_up_with_status(data.substr(i + 1, data.size() - i - 1));
                if (remain != -1) {
                    ans = max(ans, remain + 1);
                }
            }
        }

        return dp[data] = ans;
    }

    Node _root;
};


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;

        Trie trie;
        for (const auto& word : words) {
            trie.insert(word.c_str());
        }

        dp.clear();
        for (const auto& word : words) {
            if (trie.break_up(word)) {
                ret.emplace_back(word);
            }
        }

        return ret;
    }
};
// @lc code=end
