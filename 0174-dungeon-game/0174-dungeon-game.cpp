class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int row = m-1; row >=0; row--)
        {
            for(int col = n-1; col >=0; col--)
            {
                int right = 1e9;
                int down = 1e9;
                if(row + 1 < m)
                    down = dp[row+1][col];
                if(col + 1 < n)
                    right = dp[row][col+1];
                if(down == 1e9 && right == 1e9)
                {
                    if(dungeon[row][col] > 0)
                        dp[row][col] = 0;
                    else
                        dp[row][col] = -dungeon[row][col] + 1;
                }
                else
                {
                    int mini = min(right,down);
                    if(dungeon[row][col] > 0)
                    {
                        if(dungeon[row][col] - mini >= 0)
                            dp[row][col] = 0;
                        else
                            dp[row][col] = mini - dungeon[row][col];
                    }
                    else
                    {
                        dp[row][col] = -dungeon[row][col] + mini;
                        if(mini == 0)
                            dp[row][col]++;
                    }
                }
                
            }
        }
        return  (dp[0][0] <= 0) ? 1: dp[0][0];
    }
};