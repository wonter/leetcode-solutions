/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);

        if (monotonic_st.empty() || x <= monotonic_st.top()) {
            monotonic_st.push(x);
        }
    }
    
    void pop() {
        int x = st.top();
        st.pop();

        if (!monotonic_st.empty() && monotonic_st.top() == x) {
            monotonic_st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return monotonic_st.top();
    }

private:
    stack<int> st;
    stack<int> monotonic_st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

