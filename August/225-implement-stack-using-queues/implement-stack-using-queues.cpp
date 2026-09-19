class MyStack {
public:
    queue<int>q1;

    MyStack() {
        
    }
    
    void push(int x) {
        int n = q1.size();

        q1.push(x);

        while(n>0){
            q1.push(q1.front());
            q1.pop();
            n--;
        }

    }
    
    int pop() {
        int num = q1.front();
        q1.pop();
        return num;
    }
    
    int top() {
        int num = q1.front();
        return num;
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