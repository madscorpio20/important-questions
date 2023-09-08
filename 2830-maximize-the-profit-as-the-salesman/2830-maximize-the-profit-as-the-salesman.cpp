class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int maxi = 0;
        sort(offers.begin(),offers.end());
        int siz = offers.size();
        vector<int> dp(siz);
        for(int i=siz-1; i>=0; i--){
            int s = i+1;
            int e = siz-1;
            int ans = -1;
            int target = offers[i][1];
            while(s<=e){
                int mid = (s+e)/2;
                if(offers[mid][0] > target){
                    e = mid-1;
                    ans = mid;
                }else{
                    s = mid+1;
                }
            }
            if(ans!=-1){
                dp[i] = offers[i][2] + dp[ans];
            }else{
                dp[i] = offers[i][2];
            }
            maxi = max(maxi,dp[i]);
            dp[i] = maxi;
        }
        return maxi;
    }
};