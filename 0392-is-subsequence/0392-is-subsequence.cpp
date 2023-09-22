class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n < m) return false;
        int i1 = 0;
        int i2 = 0;
        while(i2 < n && i1 < m){
            if(s[i1] == t[i2]){
                i1++;
                i2++;
            }else{
                i2++;
            }
        }
        if(i1 == m) return true;
        return false;
    }
};