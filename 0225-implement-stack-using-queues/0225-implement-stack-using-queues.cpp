class MyStack {
public:
    int size;
    queue<int> q;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        size++;
    }
    
    int pop() {
        if(size == 0)
            return -1;
        queue<int> q2;
        while(q.size()> 1){
            q2.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        while(q2.size()!=0){
            q.push(q2.front());
            q2.pop();
        }
        size--;
        return ans;
    }
    
    int top() {
        if(size == 0)
            return -1;
        return q.back();
    }
    
    bool empty() {
        return size == 0;
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