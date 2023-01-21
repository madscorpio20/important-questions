//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash;
        for(int i=0; i<n; i++)
        hash.push_back(i);
        dp[0] = 1;
        int overallMax = 1;
        int ind = 0;
        for(int i=0; i<n; i++)
        {
            int maxi = 0;
            for(int j=0; j<i; j++)
            {
                if(arr[j] < arr[i])
                {
                    if(dp[j] > maxi)
                    {
                        maxi = dp[j];
                        hash[i] = j;
                    }
                }
            }
            dp[i] = maxi+1;
            if(dp[i] > overallMax)
            {
                overallMax = dp[i];
                ind = i;
            }
        }
        vector<int> ans;
        while(hash[ind]!=ind)
        {
            ans.push_back(arr[ind]);
            ind = hash[ind];
        }
        ans.push_back(arr[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends