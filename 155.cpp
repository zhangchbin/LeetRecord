class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>minval;
    stack<int>val;
    MinStack() {
        
    }
    
    void push(int val) {
        this->val.push(val);
        if(this->minval.empty()) this->minval.push(val);
        else this->minval.push(min(this->minval.top(), val));
    }
    
    void pop() {
        this->minval.pop();
        this->val.pop();
    }
    
    int top() {
        return this->val.top();
    }
    
    int getMin() {
        return this->minval.top();
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
