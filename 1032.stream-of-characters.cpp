/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

struct TrieNode {
    TrieNode() : end(false) {
        fill(child, child + 26, nullptr);
    }

    bool end;
    TrieNode* child[26];
};

class Trie {
public:
    Trie() : root(new TrieNode) {  }
    ~Trie() {
        if (root) {
            delete root;
        }
    }

    void insert(const std::string& str) {
        if (str.empty()) {
            return;
        }

        TrieNode *node = root;
        for (char ch : str) {
            if (node->child[ch - 'a'] == nullptr) {
                node->child[ch - 'a'] = new TrieNode();
            }
            node = node->child[ch - 'a'];
        }
        node->end = true;
    }

    bool lookup_prefix(const deque<char>& que) {
        TrieNode *node = root;
        for (char ch : que) {
            if (node->end) {
                return true;
            }
            if (node->child[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->child[ch - 'a'];
        }
        return node->end;
    }

private:
    TrieNode *root;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string word : words) {
            reverse(word.begin(), word.end());
            _trie.insert(word);
        }
    }
    
    bool query(char letter) {
        _que.push_front(letter);
        while (_que.size() > 2000) {
            _que.pop_back();
        }
        return _trie.lookup_prefix(_que);
    }

private:
    Trie        _trie;
    deque<char> _que;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

