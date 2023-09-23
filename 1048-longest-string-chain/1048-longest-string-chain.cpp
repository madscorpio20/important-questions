class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        map<string,int> v;

        sort(words.begin(),words.end(),cmp);

        for(int i=0; i<words.size(); i++){
            v[words[i]] = 1;
        }
        int maxi = 1;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                string sub = words[i].substr(0,j) + words[i].substr(j+1,words[i].size() - (j+1));
                if(v[sub]){
                    v[words[i]] = max(v[words[i]], v[sub] + 1);
                    maxi = max(maxi,v[words[i]]);
                }
            }
            cout<<words[i]<<" "<<v[words[i]]<<endl;
        }
        return maxi;
    }
};