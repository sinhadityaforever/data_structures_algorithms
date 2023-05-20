class MyStack {
   
    queue<int> q1;
    queue<int> q2;
    
public:
    
    
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        swap(q2, q1);
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */