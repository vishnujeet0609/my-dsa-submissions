class MyQueue {
private:
    stack<int> st1;
    stack<int>st2;

public:
    MyQueue() {}

    void push(int x) { st1.push(x); }

    void helper(){
         while (!st1.empty()) {
            int temp = st1.top();
            st1.pop();
            st2.push(temp);
        }
    }

    int pop() {
        if (!st2.empty()) {
            int top = st2.top();
            st2.pop();
            if (st2.empty()) {
                helper();
            }
            return top;
        }
        helper();
        if(!st2.empty()){
            int top = st2.top();
            st2.pop();
            return top;
        }
        return -1;
    }

    int peek() {
        if (!st2.empty()) {
            int top = st2.top();
            return top;
        }
       helper();
        if(!st2.empty()){
            int top = st2.top();
            return top;
        }
        return -1;
     }

    bool empty() { return st1.empty() && st2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */