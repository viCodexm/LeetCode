class MyQueue {
public:
    stack<int> st, st2;
    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        for (;!st.empty();st.pop())
            st2.push(st.top());
        int elem = st2.top(); st2.pop();
        for (;!st2.empty();st2.pop())
            st.push(st2.top());
        return elem;
    }
    
    int peek() {
        for (;!st.empty();st.pop())
            st2.push(st.top());
        int elem = st2.top();
        for (;!st2.empty();st2.pop())
            st.push(st2.top());
        return elem;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */