class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        map<int,vector<char>> mp;
        
        for(int i=0; i<s.size();){
            int st = i;
            int e = i;
            while(e<s.size() && s[st] == s[e]){
                e++;
            }
            char curr = s[i];
            mp[e-st].push_back(curr);
            i = e;
        }
        int cnt = 0;
        for(auto it: mp){
            int curr = it.first;
            vector<char> v = it.second;
            for(int i=1; i<v.size(); i++){
                int k = curr;
                while(mp.find(k)!=mp.end() && k != 0){
                    k--;
                }
                if(k!=0){
                    mp[k].push_back(v[i]);
                    cnt+= curr - k;
                }else{
                    cnt+= curr;
                }
            }
        }
        return cnt;
    }
};