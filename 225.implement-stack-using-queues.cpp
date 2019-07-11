/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (39.17%)
 * Likes:    344
 * Dislikes: 431
 * Total Accepted:    134K
 * Total Submissions: 336.5K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() : _idx(0) { }

    /** Push element x onto stack. */
    void push(int x) {
        _que[_idx].push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (_que[_idx].size() != 1) {
            _que[_idx^1].push(_que[_idx].front());
            _que[_idx].pop();
        }

        int ret = _que[_idx].front();
        _que[_idx].pop();
        _idx ^= 1;

        return ret;
    }

    /** Get the top element. */
    int top() {
        int ret = 0;

        while (!_que[_idx].empty()) {
            ret = _que[_idx].front();
            _que[_idx^1].push(ret);
            _que[_idx].pop();
        }

        _idx ^= 1;

        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _que[_idx].empty();
    }

private:
    int        _idx;
    queue<int> _que[2];
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

