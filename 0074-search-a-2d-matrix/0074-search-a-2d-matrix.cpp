class Solution {
public:
    int findInRow(vector<vector<int>> &matrix, int target){
        int s = 0;
        int e = matrix.size()-1;
        int mid = (s+e)/2;
        int prev = -1;
        while(s<e){
            mid = (s+e)/2;
            if(matrix[mid][0] == target)
                return mid;
            else if(matrix[mid][0] > target){
                e = mid-1;
            }
            else
                s = mid+1;
            
        }
        mid = (s+e)/2;
        if(matrix[mid][0] > target && mid != 0)
            return mid-1;
        return mid;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findInRow(matrix,target);
        cout<<row<<endl;
         bool ans = binary_search(matrix[row].begin(), matrix[row].end(),target);
        return ans;
    }
};