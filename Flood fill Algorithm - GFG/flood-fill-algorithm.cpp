//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void find(int sr, int sc, int newColor, vector<vector<int>> &image, vector<vector<int>> &vis)
    {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int val = image[sr][sc];
        image[sr][sc] = newColor;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                pair<int,int> curr = q.front();
                int currRow = curr.first;
                int currCol = curr.second;
                q.pop();
                if(currRow+1 < image.size() && !vis[currRow+1][currCol] && image[currRow+1][currCol] == val)
                {
                    image[currRow+1][currCol] = newColor;
                    vis[currRow+1][currCol] = 1;
                    q.push({currRow+1,currCol});
                }
                if(currRow-1 >= 0 && !vis[currRow-1][currCol] && image[currRow-1][currCol] == val)
                {
                    image[currRow-1][currCol] = newColor;
                    vis[currRow-1][currCol] = 1;
                    q.push({currRow-1,currCol});
                }
                if(currCol+1 < image[0].size() && !vis[currRow][currCol+1] && image[currRow][currCol+1] == val)
                {
                    image[currRow][currCol+1] = newColor;
                    vis[currRow][currCol+1] = 1;
                    q.push({currRow,currCol+1});
                }
                if(currCol-1 >= 0 && !vis[currRow][currCol-1] && image[currRow][currCol-1] == val)
                {
                    image[currRow][currCol-1] = newColor;
                    vis[currRow][currCol-1] = 1;
                    q.push({currRow,currCol-1});
                }
                
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(),0));
        vector<vector<int>> output = image;
        find(sr,sc,newColor,image,vis);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends