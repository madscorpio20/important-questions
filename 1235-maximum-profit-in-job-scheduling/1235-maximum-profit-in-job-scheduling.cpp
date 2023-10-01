class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        return v1[1] <=v2[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v(n, vector<int> (3));
        
        for(int i=0; i<startTime.size(); i++){
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(2));
            dp[0] = {v[0][1], v[0][2]};
            for(int i=1; i<n; i++){ 
                if(v[i][0] >= dp[i-1][0]){
                    dp[i][0] = v[i][1];
                    dp[i][1] = dp[i-1][1] + v[i][2];
                }else{
                    // cout<<"in"<<endl;
                    int s = 0;
                    int e = i-1;
                    int ans = -1;
                    int target = v[i][0];
                    while(s<=e){
                        int mid = (s+e)/2;
                        if(dp[mid][0] <= target ){
                            ans = mid;
                            s = mid+1;
                        }else{
                            e = mid-1;
                        }
                    }
                    dp[i][0] = v[i][1];
                    if(ans == -1){
                        dp[i][1] = max(dp[i-1][1],  v[i][2]);
                    }else{
                        dp[i][1] = max(dp[i-1][1], dp[ans][1] + v[i][2]);
                    }
                }
            }
        return dp[n-1][1];
    }
};