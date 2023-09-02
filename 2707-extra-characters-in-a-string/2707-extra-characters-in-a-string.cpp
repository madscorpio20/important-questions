class Solution {
public:
    int helper(string &s, int st, int end, vector<string> &dictionary, map<string,int> &m, vector<vector<int>> &dp){
        // cout<<end<<endl;
        if(end == s.size()){
            string curr = "";
            for(int i = st; i<end; i++){
                curr += s[i];
            }
            if(!m[curr])
                return end - st;
            return 0;
        }
        if(dp[st][end]!=-1)
            return dp[st][end];
        
        // cout<<end<<endl;

        int pick = helper(s, st,end+1,dictionary,m,dp);
        int notpick = helper(s,end+1,end+1,dictionary,m,dp);
        string curr = "";
        for(int i=st; i<=end; i++){
            curr+= s[i];
        }
        if(!m[curr]){
            notpick += end - st + 1;
        }
        return dp[st][end] = min(pick,notpick);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> m;
        int n = s.size();
        for(int i=0; i<dictionary.size(); i++){
            m[dictionary[i]]++;
        }
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(s,0,0,dictionary,m,dp);
    }
};