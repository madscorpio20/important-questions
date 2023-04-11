class Solution {
public:
    string removeStars(string s) {
        vector<char> v(s.size(), '0');
        int ind = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '*')
            {
                v[ind] = '0';
                ind--;
            }
            else
            {
                v[ind+1] = s[i];
                ind++;
            }
        }
        string ans = "";
        for(auto it: v)
        {
            if(it!= '0')
                ans+= it;
        }
        return ans;
    }
};