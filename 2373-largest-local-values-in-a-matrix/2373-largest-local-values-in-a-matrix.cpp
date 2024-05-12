class Solution {
public:
    int findmax(int x, int y, vector<vector<int>> &grid)
    {
        int maxi = 0;
        for(int i=x; i<=x+2; i++)
        {
            for(int j = y; j<=y+2; j++)
            {
               maxi = max(maxi,grid[i][j]); 
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,0));
        for(int i=0; i<n-2; i++)
        {
            for(int j=0; j<n-2; j++)
            {
                maxLocal[i][j] = findmax(i,j,grid);
            }
        }
        return maxLocal;
    }
};