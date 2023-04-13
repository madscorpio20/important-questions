class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushInd = 1;
        int popInd = 0;
        s.push(pushed[0]);
        int n = pushed.size();
        while(pushInd < n)
        {
            if(s.empty() || s.top() != popped[popInd])
            {
                s.push(pushed[pushInd]);
                pushInd++;
            }
            else
            {
                s.pop();
                popInd++;
            }
            
        }
        while(!s.empty())
        {
            if(s.top()!=popped[popInd])
                return false;
            popInd++;
            s.pop();
        }
        return true;
    }
};