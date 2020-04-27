#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start

class MiddleStream{
public:
    void insert(int x) {
        if (_max_heap.empty() || x <= *_max_heap.begin()) {
            _max_heap.insert(x);
        } else {
            _min_heap.insert(x);
        }
        ajudge();
    }

    void erase_one(int x) {
        auto it = _max_heap.find(x);
        if (it != _max_heap.end()) {
            _max_heap.erase(it);
            ajudge();
            return;
        }

        it = _min_heap.find(x);
        if (it != _min_heap.end()) {
            _min_heap.erase(it);
            ajudge();
            return;
        }
    }

    double middle() {
        assert(abs(static_cast<int>(_max_heap.size() - _min_heap.size())) <= 1);

        if (_max_heap.size() > _min_heap.size()) {
            return *_max_heap.begin();
        }

        if (_min_heap.size() > _max_heap.size()) {
            return *_min_heap.begin();
        }

        return 1.0 * (static_cast<long long>(*_max_heap.begin()) + *_min_heap.begin()) / 2;
    }

    void print() {
        for (int x : _max_heap) {
            cout << x << " ";
        }
        cout << "| ";
        for (int x : _min_heap) {
            cout << x << " ";
        } 
        cout << endl;
    }

private:
    void ajudge() {
        while (_max_heap.size() >= _min_heap.size() + 2) {
            _min_heap.insert(*_max_heap.begin());
            _max_heap.erase(_max_heap.begin());
        }

        while (_min_heap.size() >= _max_heap.size() + 2) {
            _max_heap.insert(*_min_heap.begin());
            _min_heap.erase(_min_heap.begin());
        }
    }


    multiset<int, greater<int>> _max_heap;
    multiset<int, less<int>> _min_heap;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MiddleStream ms;
        for (int i = 0; i < k - 1; ++i) {
            ms.insert(nums[i]);
        }

        vector<double> ret;
        for (int i = k - 1; i < nums.size(); ++i) {
            if (i >= k) {
                ms.erase_one(nums[i - k]);
            }
            ms.insert(nums[i]);
            ret.emplace_back(ms.middle());
        }
        return std::move(ret);
    }
};
// @lc code=end
