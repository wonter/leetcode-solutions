/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (43.20%)
 * Likes:    583
 * Dislikes: 111
 * Total Accepted:    155K
 * Total Submissions: 353.3K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() : _idx(0) { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _que[_idx].push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (_que[_idx^1].empty()) {
            dump();
        }

        int ret = _que[_idx^1].front();
        _que[_idx^1].pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (_que[_idx^1].empty()) {
            dump();
        }

        return _que[_idx^1].front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _que[0].empty() && _que[1].empty();
    }

private:
    void dump() {
        while (!_que[_idx].empty()) {
            int front = _que[_idx].front();
            _que[_idx].pop();
            _que[_idx^1].push(front);
        }
    }

    int _idx;
    queue<int> _que[2];
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

