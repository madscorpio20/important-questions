class Solution {
public:
    int maxScore(string s) {
        int totalOne = 0;
        for(auto it: s){
            if(it == '1')totalOne++;
        }
        int left = 0;
        int right = totalOne;
        int res = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0')left++;
            else right--;
            res = max(res, left + right);
        }
        return res;
    }
};