class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> suffixMin(n);
        int currMin = 27;
        for(int i=n-1; i>=0; i--)
        {
            currMin = min(currMin,s[i] - 'a');
            suffixMin[i] = currMin;
        }
        stack<char> st;
        string output;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top() - 'a' <= suffixMin[i])
            {
                output += st.top();
                st.pop();
            }
            if(s[i] - 'a' != suffixMin[i])
            {
                st.push(s[i]);
            }
            else
            {
                output+= s[i];
            }
        }
        while(!st.empty())
        {
            output+= st.top();
            st.pop();
        }
        return output;
    }
};