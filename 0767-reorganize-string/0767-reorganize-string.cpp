class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26,0);
        for(int i = 0; i<s.size(); i++){
            v[s[i] - 'a']++;
        }
        int max_ind = 0;
        for(int i=0; i<26; i++){
            if(v[i] > v[max_ind])
                max_ind = i;

        }
        int i = 0;
        vector<char> ans(s.size(), '\0');
        while(v[max_ind] > 0 && i<s.size()){
            char ch = 'a' + max_ind;
            ans[i] = ch;
            v[max_ind]--;
            i+=2;

        }
        if(i >= s.size() && v[max_ind]!= 0 )
            return "";
        if(i >=s.size())
            i= 1;
        for(int j=0; j<26; j++){
            
            while(v[j] > 0){
                cout<<i<<" ";
                char ch = 'a' + j;
                
                ans[i] = ch;
                v[j]--;
                i+=2;
                if(i >= s.size())
                    i = 1;
            }   
            
        }
        string res = "";
        for(int i=0; i<s.size(); i++){
            res += ans[i];
        }
        return res;
    }
};