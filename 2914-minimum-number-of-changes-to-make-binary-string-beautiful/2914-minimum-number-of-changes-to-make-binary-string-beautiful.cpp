class Solution {
public:
    int minChanges(string s) {
        int i=0;
        int cnt = 0;
        while(i<s.size()){
            if(s[i]!=s[i+1]){
                cnt++;
            }
            i+=2;
        }
        return cnt;
    }
};