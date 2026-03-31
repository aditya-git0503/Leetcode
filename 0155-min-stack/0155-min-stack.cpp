class MinStack {
public:
    stack<int> st;
    int m = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            m = val;
            st.push(val);
        }
        else{
            if(val > m){
                st.push(val);
            }
            else{
                st.push(2*val - m);
                m = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        int x = st.top();
        st.pop();
        if(x < m){
            m = 2 * m - x;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        int x = st.top();
        if(m < x)
            return x;
        return m;
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */