class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;
        int i1 = 0;
        int i2 = 0;
        while(i2 < t.size()){
            if(s[i1] == t[i2]){
                i1++;
                i2++;
            }else{
                i2++;
            }
        }
        if(i1 == s.size()) return true;
        return false;
    }
};