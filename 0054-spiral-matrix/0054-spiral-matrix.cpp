class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rowLast = m-1;
        int colLast = n-1;
        int rowStart = 0;
        int colStart = 0;
        int i = 0;
        int j =0;
        vector<int> ans;
        while(ans.size() < m*n-1){
            i = rowStart;
            j = colStart;
            while(j < colLast && ans.size() < m*n){
                ans.push_back(matrix[i][j]);
                j++;
            }
            colLast--;

            while(i < rowLast && ans.size() < m*n){
                ans.push_back(matrix[i][j]);
                i++;
            }
            rowLast--;
            
            while(j>colStart && ans.size() < m*n){
                ans.push_back(matrix[i][j]);
                j--;
            }
            colStart++;
            while(i > rowStart && ans.size() < m*n){
                ans.push_back(matrix[i][j]);
                i--;
            }
            rowStart++;
        }
        if(ans.size() < m*n){
            ans.push_back(matrix[rowStart][colStart]);
        }
        return ans;
    }
};