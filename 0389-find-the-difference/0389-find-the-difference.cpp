class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        int ind = 0;
        while(ind <s.size()){
            if(s[ind]!=t[ind]) return t[ind];
            ind++;
        }
        return t[t.size()-1];
    }
};