class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
        
        s1.push(x);
        while(!s2.empty()){
            int tmp = s2.top();
            s2.pop();
            s1.push(tmp);
        }
    }
    
    int pop() {
        int tmp = s1.top();
        s1.pop();
        return tmp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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