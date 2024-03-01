class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cntOne = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                cntOne++;
            }
        }
        string ans(s.size(),'0');
        ans[s.size()-1] = '1';
        cntOne--;
        int ind = 0;
        while(cntOne > 0){
            ans[ind] = '1';
            cntOne--;
            ind++;
        }
        return ans;
    }
};