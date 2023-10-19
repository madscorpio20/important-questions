class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]){
            return v1[1] >= v2[1];
        }else{
            return v1[0] < v2[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),cmp);
        int n = envelopes.size();
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1; i<n; i++){
            if(envelopes[i][1] > dp[dp.size()-1]){
                dp.push_back(envelopes[i][1]);
                continue;
            }
            int s = 0;
            int e = dp.size() -1;
            int ans = -1;
            while(s <= e){
                int mid = (s + e)/2;
                if(dp[mid] >= envelopes[i][1]){
                    ans = mid;
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            if(ans != -1){
                dp[ans] = envelopes[i][1]; 
            }
        }
        return dp.size();
    }
};