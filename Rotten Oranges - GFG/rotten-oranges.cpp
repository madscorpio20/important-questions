//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int time = -1;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                q.push({i,j});
            }
        }
        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!q.empty())
        {
            time++;
            int siz = q.size();
            for(int i=0; i<siz; i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;
                if(row-1 >=0 && !vis[row-1][col] && grid[row-1][col] == 1)
                {
                    vis[row-1][col] = 1;
                    grid[row-1][col] = 2;
                    q.push({row-1,col});
                }
                if(row+1 < m && !vis[row+1][col] && grid[row+1][col] == 1)
                {
                    vis[row+1][col] = 1;
                    grid[row+1][col] = 2;
                    q.push({row+1,col});
                }
                if(col-1 >=0 && !vis[row][col-1] && grid[row][col-1] == 1)
                {
                    vis[row][col-1] = 1;
                    grid[row][col-1] = 2;
                    q.push({row,col-1});
                }
                if(col+1 < n && !vis[row][col+1] && grid[row][col+1] == 1)
                {
                    vis[row][col+1] = 1;
                    grid[row][col+1] = 2;
                    q.push({row,col+1});
                }
                
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                return -1;
            }
        }
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends