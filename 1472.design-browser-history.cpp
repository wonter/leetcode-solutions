/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) : _current(homepage) {  }
    ~BrowserHistory() = default;
    
    void visit(string url) {
        _back.push(_current);
        clear_forward();

        _current = url;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps && !_back.empty(); ++i) {
            _forward.push(_current);
            _current = _back.top();
            _back.pop();
        }
        return _current;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps && !_forward.empty(); ++i) {
            _back.push(_current);
            _current = _forward.top();
            _forward.pop();
        }
        return _current;
    }

private:
    void clear_forward() {
        while (!_forward.empty()) {
            _forward.pop();
        }
    }

    string _current;
    stack<string> _back;
    stack<string> _forward;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

