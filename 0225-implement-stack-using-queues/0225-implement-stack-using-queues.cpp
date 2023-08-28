class MyStack {
        queue<int> q1;
public:
    #include <queue>
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) return 0;
        q1.push(-1);
        int ans = 0;
        while(q1.front()!=-1)
        {
            ans = q1.front();
            q1.pop();
            if(q1.front()!=-1)
                q1.push(ans);
        }
        q1.pop();
        return ans;
    }
    
    int top() {
        if(q1.empty()) return 0;
        q1.push(-1);
        int ans;
        while(q1.front()!=-1)
        {
            ans = q1.front();
            q1.pop();
            q1.push(ans);
        }
        q1.pop();
        return ans;
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