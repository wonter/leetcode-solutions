/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 */

// @lc code=start
class FooBar {
private:
    int n;

    bool _foo_turn;
    std::mutex _mutex;
    std::condition_variable _cond;

public:
    FooBar(int n) {
        this->n = n;
        this->_foo_turn = true;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> guard(_mutex);

            while (!_foo_turn) {
                _cond.wait(guard);
            }

        	printFoo();

            _foo_turn = false;
            _cond.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> guard(_mutex);

            while (_foo_turn) {
                _cond.wait(guard);
            }

        	printBar();

            _foo_turn = true;
            _cond.notify_one();
        }
    }
};
// @lc code=end

