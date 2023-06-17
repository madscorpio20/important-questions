class Solution {
public:
    int find_min_operations(vector<int> &arr1, vector<int> &arr2,int ind,int prev, vector<vector<int>> &dp)
    {
        if(ind == arr1.size())
            return 0;
        int arrInd = upper_bound(arr2.begin(),arr2.end(), prev) - arr2.begin();
        if(dp[ind][arrInd] != -1)
            return dp[ind][arrInd];
        
        if(arr1[ind] <= prev){
            if(arrInd  == arr2.size())
                return dp[ind][arrInd] = 1e8;
            else{
                return dp[ind][arrInd] = find_min_operations(arr1,arr2,ind+1,arr2[arrInd],dp) + 1;
            } 
        }
        else{
                int notPick = find_min_operations(arr1,arr2,ind+1,arr1[ind], dp);
                int pick = 1e8;
                if(arrInd  != arr2.size())
                {
                    pick = find_min_operations(arr1,arr2,ind+1,arr2[arrInd],dp) + 1;
                }
            return dp[ind][arrInd] = min(pick,notPick);
        }
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<vector<int>> dp(arr1.size(),vector<int>(arr2.size()+1,-1));
        int ans = find_min_operations(arr1,arr2,0,-1,dp);
        if(ans >= 1e8)
            return -1;
        return ans;
    }
};