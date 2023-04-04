class Solution {
public:
    int partitionString(string s) {
        int i=0; 
        int cnt = 0;
        while(i < s.size())
        {
            unordered_set<char> st;
            while(!st.count(s[i]) && i <s.size())
            {
                st.insert(s[i]);
                i++;
            }
            cnt++;
            
        }
        return cnt;
    }
};