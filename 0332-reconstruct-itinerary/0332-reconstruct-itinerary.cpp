class Solution {
public:
    vector<string> dfs(unordered_map<string,vector<string>> &mp, unordered_map<string,vector<int>> &vis, string curr, vector<string> &ans,int n){
        // cout<<curr<<endl;
        if(ans.size() == n+1)
            return ans;
        for(int i=0; i<mp[curr].size(); i++){
            // cout<<i<<endl;
            if(!vis[curr][i]){
                vis[curr][i]++;
                ans.push_back(mp[curr][i]);
                vector<string> k = dfs(mp,vis,mp[curr][i], ans,n);
                if(k.size() == n+1)
                    return k;
                vis[curr][i] = 0;
                ans.pop_back();
            }
        }
        return {""};
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> mp;
        for(int i=0; i<tickets.size(); i++){
            mp[tickets[i][0]].push_back(tickets[i][1]);
            sort(mp[tickets[i][0]].begin(), mp[tickets[i][0]].end());
        }
        
        unordered_map<string,vector<int>> vis;
        for(auto it: mp){
            vis[it.first] = vector<int> (it.second.size(),0);
        }
        vector<string> ans;
        ans.push_back("JFK");
        return dfs(mp,vis,"JFK",ans,tickets.size());
        return ans;
    }
};