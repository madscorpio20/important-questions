class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);
        for(int i=0; i<n; i++)
        {
            prev[i] = triangle[n-1][i];
        
        }

        for(int i=n-2; i>=0; i--)
        {
            vector<int> curr(n,0);
            for(int j=0; j<=i; j++)
            {
                curr[j] = min(prev[j],prev[j+1]) + triangle[i][j];
            }
            prev = curr;
        }
        return prev[0];
    }
};