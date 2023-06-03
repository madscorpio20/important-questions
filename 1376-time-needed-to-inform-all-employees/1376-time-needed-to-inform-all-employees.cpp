class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subbordinates(n);
        int head;
        for(int i=0; i<n; i++)
        {
            if(manager[i] == -1)
            {
                head = i;
                continue;
            }
            subbordinates[manager[i]].push_back(i);
        }
        int maxi = informTime[head];
        queue<pair<int,int>> q;
        q.push({head,maxi});
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int node = front.first;
            int time = front.second;
            maxi = max(maxi,time);
            for(int i=0; i<subbordinates[node].size(); i++)
            {
                q.push({subbordinates[node][i],time+informTime[subbordinates[node][i]]});
            }
        }
        return maxi;
    }
};