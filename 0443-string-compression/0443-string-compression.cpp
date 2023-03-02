class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        vector<char> ans;
        while(i<chars.size())
        {
            int cnt = 1;
            while(i+1<chars.size() && chars[i] == chars[i+1])
            {
                cnt++;
                i++;
            }
            ans.push_back(chars[i]);
            
            if(cnt> 1)
            {
                stack<char> s;
                while(cnt> 0)
                {
                    char c = cnt%10 + '0';
                    s.push(c);
                    cnt/=10;
                }
                while(!s.empty())
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            } 
            i++;
        }
        chars = ans;
        return ans.size();
    }
};