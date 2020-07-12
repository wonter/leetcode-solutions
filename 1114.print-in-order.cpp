/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Foo {
public:
    Foo() : _now(0) { }

    void first(function<void()> printFirst) {
        unique_lock<mutex> guard(_mutex);

        while (_now != 0) {
            _cond[0].wait(guard);
        }

        printFirst();

        _now = (_now + 1) % 3;
        _cond[1].notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> guard(_mutex);

        while (_now != 1) {
            _cond[1].wait(guard);
        }

        printSecond();

        _now = (_now + 1) % 3;
        _cond[2].notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> guard(_mutex);

        while (_now != 2) {
            _cond[2].wait(guard);
        }

        printThird();

        _now = (_now + 1) % 3;
        _cond[0].notify_all();
    }

private:
    mutex _mutex;
    condition_variable _cond[3];
    int _now;
};
// @lc code=end
