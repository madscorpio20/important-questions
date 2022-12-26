//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int helpCountMin(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind1<0 && ind2<0)
        return 0;
        if(ind1 < 0)
        return ind2+1;
        if(ind2<0)
        return ind1+1;
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = helpCountMin(s1,s2,ind1-1,ind2-1,dp);
        else
        return dp[ind1][ind2] = min(helpCountMin(s1,s2,ind1-1,ind2,dp),helpCountMin(s1,s2,ind1,ind2-1,dp)) + 1;
        
    }
    int countMin(string str){
    //complete the function here
        string s1 = str;
        string s2= "";
        int siz = s1.size();
        vector<vector<int>> dp(siz+1,vector<int> (siz+1,0));
        for(int i=siz-1; i>=0; i--)
        {
            s2 += s1[i];
        }
        // return helpCountMin(s1,s2,siz-1,siz-1,dp)/2;
        for(int i=1; i<=siz; i++)
        {
            for(int j=1; j<=siz; j++)
            {
                if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return siz - dp[siz][siz];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends