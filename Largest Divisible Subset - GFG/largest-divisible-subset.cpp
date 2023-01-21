//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<int> hash;
        vector<int> dp(n,1);
        for(int i=0; i<n; i++)
        {
            hash.push_back(i);
        }
        int overallMax = 1;
        int ind = 0;
        for(int i=0; i<n; i++)
        {
            int maxi = 0;
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j] == 0 && dp[j] > maxi)
                {
                    hash[i] = j;
                    maxi = dp[j];
                }

            }
            dp[i] = maxi + 1;
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
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends