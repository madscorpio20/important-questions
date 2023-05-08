class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        int j = 0;
        int n = mat.size();
        int ans = 0;
        while(i <n)
        {
            ans += mat[i][j];
            i++;
            j++;
            
        }
        i = 0;
        j = n-1;
        while(i < n)
        {
            if(i == j)
            {
                i++;
                j--;
                continue;
            }
            ans += mat[i][j];
            i++; j--;
        }
        return ans;
    }
};