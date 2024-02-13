class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            int s = 0;
            int e = words[i].size()-1;
            bool flag = true;
            while(s < e){
                if(words[i][s] != words[i][e]){
                    flag = false;
                    break;
                }
                s++;
                e--;
            }
            if(flag){
                return words[i];
            }
        }
        return "";
    }
};