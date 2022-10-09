class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int> &vis, int curr)
    {
        for(int i=0; i<rooms[curr].size(); i++)
        {
            if(vis[rooms[curr][i]] == 0)
            {
                vis[rooms[curr][i]] = 1;
                dfs(rooms,vis,rooms[curr][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        vis[0] = 1;
        dfs(rooms,vis,0);
        for(auto it: vis)
        {
            if(it == 0)
                return false;
        }
        return true;
        
    }
};